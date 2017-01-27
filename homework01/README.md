Homework 01
===========

Activity 1

1. a) Only the system administrator and myself can interact with my folders in my private directory. However, in my public and home directorys, nd_campus and authurizored users can also interact with my files. The permissions do differ between home and public directories for the nd_campus and autorized users. In the home directory nd campus and authorized users can only lookup files in my home directory whereas in my public directory, they can read, lookup, and lock my files and directories. Myself and administrators have the same permissions across alldirectories.

b) The ACLs of nd_campus rlk and authuser rlk are present in the public directory, but not in the private. In fact, nd_campus and authuser do not have rights to the private directory. This makes it private.

2. a) The result was permission denied.
   b) ACLs because I do not have any rights in the nd.edu directory in which the web file is located. Therefore, the ACL stops me before I can write a file.

Activity 2

| Command                                                      |Elapsed Time|
|--------------------------------------------------------------|------------|
| cp -ar /usr/share/pixmaps /afs/nd.edu/user20/bhoeltin/images |2.22 seconds|
| mv images pixmaps                                            | 0 seconds  |
| mv pixmaps /tmp/bhoeltin-pixmaps                             |.736 seconds|
| rm -r /tmp/bhoeltin-pixmaps                                  |.008 seconds|   


Activity 3

1. bc < math.txt
2. bc < math.txt > results.txt
3. bc 2> /dev/nul < math.txt > results.txt
4. cat math.txt | bc  
   This is considered less efficient because two commands have to be executed before the task is accomplished as opposed to one for redirection. 

Activity 4

1. grep -o "/sbin/nologin" /etc/passwd |wc -l
2. who | cut -d ' ' -f 1| sort | uniq | wc -l
3. du -ah /etc/ 2> /dev/null | sort -nr | head -n 5 
4. ps -aux 2> /dev/null| grep "bash" | grep -v 'grep'| wc -l

Activity 5

1. a) I intially tried ctrl-Z to stop the process, but it only said it was suspended. When I used the command ps it still said that troll was running.
b) I succeeded upon killing the troll once I found out the PID of the troll using ps and killed it with the kill -KILL signal.

2. a) ps -aux 2> /dev/null| grep bhoeltin then kill -9 pid (the pid that corresponds to TROLL)
   b) kill -KILL $(pgrep -u bhoeltin TROLL) 

3. When I put in the -BUS signal, the troll said "Come ride the train, the choo choo!." When I used the -HUP signal, the troll said "You used to call me on my cellphone." Using the -INT command recieved a "NACK" response from the troll, but did not kill the terminal.