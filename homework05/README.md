Homework 05
===========

Activity 1

The hulk.py script uses multiple functions to complete its task of extracting passwords. The md5Sum function converts a string to hash. The permutations function generates all the possible permutations for a given length from a given alphabet. This is done through recursion. Then the smash function utilizes both of these, generating hashes for all possible password permutations of a given length. This is how I got the list of passwords to find. Then, I compared the possible hashes to the actual hashes from the link in order to see if any matched. if they did, the actual password was returned and put into the passwords list. This was done with list combination. In order to handle the processing on multiple cores, I utilized the prefix aspect of the function and split up the work between multiple cores. I would use a set prefix and only search the rest of the words, this was done on multiple cores. Like if the length was 4 then I would smash passwords of length 3 with prefixes [a,b...,9]. I also used a tool that made the function partial so that only one parameter had to be passed to it while everything else was set. This is then used to create the passwords. To verify that my code worked, I used doctests, the test script given to us and I got the right output overall. 

Process	          Time
1     		  4:15:10.02
2     		  1:58:33.15
4     		  1:29:20.79
8     		  42:16.19
12   		  23:10.39

The more processes used, the faster the result was found.

Having a more complex alphabet would make the program slower. Per definition of a permutation, the more members of a group being permutated, the larger the amount of permutations are possible. The more permutations, means the more posibilities to search and the longer the program takes.

Activity 2

The iv_map.py script works to go through a text file and output each word in it with its line number. In order to do this it iterates through each line of standard input and each word in that line. A count is kept of each iteration of the loop that goes through the standard in and gives the line number for the words. The line is converted to lowercase, stripped of its trailing whitespace, and split into separate words.  In order to make sure the words themselves are stripped of unwanted characters, I created a variable that held the characters that i actually wanted and used it with a line comprehension. I then outputted the word and its line number. The iv_map.py script is combined with the iv_reduce.py script in order to produce a MapReduce. The script iv_reduce.py works to aggregate the data and give a list of line numbers for a given word instead of a separate listing for each word in the text file. This is accomplished by taking the standard input from the iv_map script parsing the line for a word and its line number. If the word is not already in the dictionary of counts, then a new key for that word is set and the line number it is found at is added to the key as a value. If the word is already in the dictionary then the new line number is added to the the dictionary at that word. If a word is found more than once in a line, then the later for loop will account for the duplicates. Finally the program uses the join function to output the word with its lines. 