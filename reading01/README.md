Reading 01
==========

1.
a) The | is called a pipe operator which serves to take the standard output one command and pipes it into the standard input of the following command. In this instance, the pipe operator takes the disk usage of the /etc and feeds it to the sort command to be sorted. 

b) 2> /dev/null captures unwanted error messages from the commands before it so that it will not be passed to the sort function. 

c) > output.txt redirects the sorted list to a text file. The text file output.txt will now contain the transformed output from the du -h command.

d) The -h flag puts the disk usage information in human terms so that it can be easily understood by the user.

e) No the command is different because the error is not suppressed until the end. This could result in unwanted content in the output file if an error does occur.

2. 
a) cat 2002-* > 2002
b) cat *-12 > December
c) cat *{01..06}
d) cat {2002..2006..2}-{01..12..2}
e) cat {2002..2004}-{09..12}

3. 
a) The Huxley and Tux files are executable by the owner.
b) The Huxley and Tux files are readable by the users group.
c) None of the files are writable by the world.
d) chmod 755 Tux
e) chmod 600 Tux

4.
a) To suspend the process one would press Ctrl-z.
b) To resume the process and bring it back to the foreground, the fg command would be used.
c) I would use ctrl-d to signal end of input to the bc process.
d) I would use the ctrl-C signal to kill the process.
e) First, I would have to figure out the processes PID in order to kill it. This can be done with the ps command and the corresponding username of the person running the process. A password may be required. Then I would use kill -HUP followed by the PID to kill the process.