#! /bin/bash                                                                                    

if [ "$#" -eq "0" ]; then
    curl -s http://www.zipcodestogo.com/Indiana/ | grep -Eo "[0-9]{5}/" | cut -c 1-5 | sort
    exit 1
fi

if [ "$1" == "-h" ]; then
    cat <<EOF
Usage: zipcode.sh

  -c      CITY    Which city to search
  -f      FORMAT  Which format (text, csv)
  -s      STATE   Which state to search (Indiana)

If not CITY is specified, then all the zip codes for the STATE are displayed.
EOF
    exit 1
fi


while [ "$#" -gt "0" ]; do
    if [ "$1" == "-s" ]; then
	shift
	STATE="$1"
	STATE=$(echo $STATE | sed -E 's/ /%20/g')
	shift
	if [ "$1" == "-c" ]; then
	    shift
	    CITY="$1"
	    shift
	    if [ "$1" == "-f" ]; then
		shift
	        if [ "$1" == "csv" ]; then
		    curl -s http://www.zipcodestogo.com/{$STATE}/ | grep "/$CITY/" | grep -Eo "[0-9]{5}" | sort  | uniq | tr '\n' ',' 
		elif [ "$1" == "text" ]; then
		    curl -s http://www.zipcodestogo.com/{$STATE}/ | grep "/$CITY/" | grep -Eo "[0-9]{5}" | sort  | uniq
		else 
		    echo "Invalid format type."
		fi
            else
	       curl -s http://www.zipcodestogo.com/{$STATE}/ | grep "/$CITY/" | grep -Eo "[0-9]{5}" | sort  | uniq
	    fi
	else 
	    if [ "$1" == "-f" ]; then
		shift
		if [ "$1" == "csv" ]; then
		    curl -s http://www.zipcodestogo.com/{$STATE}/ | grep -Eo "[0-9]{5}" | cut -c 1-5 | sort | tr '\n' ',' 
		elif [ "$1" == "text" ]; then
		    curl -s http://www.zipcodestogo.com/{$STATE}/ | grep -Eo "[0-9]{5}/" | cut -c 1-5 | sort
		else
		    echo "Invalid format type."
		fi
            else
		curl -s http://www.zipcodestogo.com/{$STATE}/ | grep -Eo "[0-9]{5}/" | cut -c 1-5 | sort
            fi
	fi
    else
	if [ "$1" == "-f" ]; then
	    shift
            if [ "$1" == "csv" ]; then
		curl -s http://www.zipcodestogo.com/Indiana/ | grep -Eo "[0-9]{5}/" | cut -c 1-5 | tr '\n' ',' 
            elif [ "$1" == "text" ]; then
	      curl -s http://www.zipcodestogo.com/Indiana/ | grep -Eo "[0-9]{5}/" | cut -c 1-5 | sort
            else
	       echo "Invalid format type."
	    fi
	else
	    curl -s http://www.zipcodestogo.com/Indiana/ | grep -Eo "[0-9]{5}/" | cut -c 1-5 | sort
	fi
	
    fi
    shift
done

exit 1;