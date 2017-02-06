Homework 02
===========

Activity 1

To ensure that a command with no arguments was handled, I put an if then statement into the beginning of my script file that would check the number of arguments using $# and compare that to zero. If the $# equalled zero, then I would send out an error message that said arguments please and exit the program. The commands to decompress the files came from flags associated with the tar command. For .tgz or .tar.gz files, the -z flag was needed. For .tbz or .tar.bz2, the j flag was need. For .txz or .tar.xz, the J flag was needed. However, the zip file did not need the tar command just the unzip command. The most challenging aspect of the code was figuring out the syntax of the case structure. I did not know that you could use or statements for the case syntax so that took me a while to figure out.

Activity 2

To display random messages to the user I used the shuf command and the -n flag to indicate the number of lines that I wanted. To trap the signals, I used the trap command at the beginning of the program. It caught SIGHUP, SIGINT, and SIGTERM signals and exited the program if they were caught. To read input from the user I used the read command with the -p flag to read a single line of code after a prompt to the user. The command then put that single line of code intot the variable question. The most challenging aspect of writing this code was figuring out how to pipe outputs directly to variables. I am always a little fuzzy with the proper way to call variables and such so it took me a bit to get the right syntax and structure. 


Activity 3


1.  My first step was to scan `xavier.h4x0r.space` for a HTTP port:

   Command: nmap -Pn xavier.h4x0r.space

   Output: 
   Starting Nmap 5.51 ( http://nmap.org ) at 2017-02-03 12:50 EST
   Nmap scan report for xavier.h4x0r.space (129.74.160.130)
   Host is up (0.00065s latency).
   Not shown: 946 filtered ports, 50 closed ports
   PORT     STATE SERVICE
   22/tcp   open  ssh
   8888/tcp open  sun-answerbook
   9111/tcp open  DragonIDSConsole
   9876/tcp open  sd

   Nmap done: 1 IP address (1 host up) scanned in 7.24 seconds

   There are two ports in the 9000-9999 range

2. Next, I tried to access the HTTP server:

   Command: curl 129.74.160.130:9111

   Output: I got a character that was saying all sorts of things to me. 

   "Hello who might you be"

   "NAME?"

   "Hmm... GET / HTTP/1.1?

   That name sounds familiar... what message do you have for me?"

   MESSAGE?  _________________________________________ 
   / I'm sorry sugar, but I don't understand \
   | this message:                           |
   |                                         |
   | User-Agent: curl/7.19.7                 |
   | (x86_64-redhat-linux-gnu)               |
   | libcurl/7.19.7 NSS/3.15.3 zlib/1.2.3    |
   | libidn/1.18 libssh2/1.4.2               |
   |                                         |
   | Perhaps, it wasn't meant for you.       |
   |                                         |
   | Why don't you go back to the DOORMAN or |
   \ BOBBIT?   

3. Next, I tried the port number 9876:

   Command: curl 129.74.160.130:9876

   Output: I got a dinosaur who said the following:

   Once the LOCKBOX has been located, you |
   | must use your hacking skills to        |
   | _bruteforce_ the LOCKBOX program until |
   | it reveals the passcode!               |
   |                                        |
   \ Good luck! 

4. I used what the dinosaur said and tried to get my passcode by locating the lockbox with the pathname.

   Command: find ~pbui/pub/oracle/lockboxes | grep bhoeltin

   Output: I got 101 different files that pertained to my netID and lockbox. However the correct one was /afs/nd.edu/user15/pbui/pub/oracle/lockboxes/2c305470/265e5f00/3bb3e03c/434abbc9/bhoeltin.lockbox


5. Next, I tried to open the lockboax with brute force:

   Command: strings /afs/nd.edu/user15/pbui/pub/oracle/lockboxes/2c305470/265e5f00/3bb3e03c/434abbc9/bhoeltin.lockbox

   Output: I got 5000 lines of random text 

6. I Then used that following command to save the output from step 5 into a variable named STRING

   Command: STRING=$(strings /afs/nd.edu/user15/pbui/pub/oracle/lockboxes/2c305470/265e5\f00/3bb3e03c/434abbc9/bhoeltin.lockbox)

   Output: nothing

7. After getting that output I used a for loop to go through each line in the STRING variable to see if any of them would open up my lockbox

   Command:
   for password in $STRING; do
   > /afs/nd.edu/user15/pbui/pub/oracle/lockboxes/2c305\470/265e5\f00/3bb3e03c/434abbc9/bhoeltin.lockbox $password
   > done

   Output: 1f51a397aea3be025b8a706551b2c047

8. Next I used this password with my netID to get access to the HTTP port:

   Command: curl 129.74.160.130:9876/bhoeltin/1f51a397aea3be025b8a706551b2c047

9. I did what the character told me and wen to slack to message Bobbit and sent:

   Command: !veriy bhoeltin "1f51a397aea3be025b8a706551b2c047"

   Output: Greetings bhoeltin! Please tell the ORACLE the following MESSAGE: b3VicnlndmE9MTQ4NjE0NjI3OQ==

10. Lastly, to talk to the oracle I used the nc command with the IP address and port number:

    Command: nc 129.74.160.130 9111

    Output: 

    Hello who might you be?

    bhoeltin

     Hmm... bhoeltin?                  \
     |                                   |
     | That name sounds familiar... what |
     \ message do you have for me? 

     b3VicnlndmE9MTQ4NjE0NjI3OQ==

     Ah yes... bhoeltin!                   \
     |                                       |
     | You're smarter than I thought. I can  |
     | see why the instructor likes you.     |
     |                                       |
     | You met BOBBIT about 5 minutes ago... |
     \ What took you so long?   

     
     Reason?

      Hmm... Sorry, kid. You got the gift, \
      | but it looks like you're waiting for |
      | something.                           |
      |                                      |
      | Your next life, maybe. Who knows?    |	
      \ That's the way these things go.  

