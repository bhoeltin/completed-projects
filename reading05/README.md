Reading 05
==========

Question 1

1. The import sys allows python to import objecs from sys.
2. The for loop goes through each argument on the command line starting with the first argument after the command .
3. The trailing comma allows next argument to be printed on the same line as the previous argument. It prevents the new line character from being outputted.

Question 2

1. The loop runs through the args list finding arguments that begin with a - and that the argument is at least two characters in length. The loop will stop once any of these things is no longer true. This means the loop only parses the command line for flags.

2. The code will signal that no path was given at the command line so it should read standard input. If a path is found in args then it will open that and use that as the program input.

3. line.rstrip() returns a copy of the string in which the whitespace has been stripped from the end of the string. It will make sure no whitespace is printed and that the ending goes on the actual end of the word. 
