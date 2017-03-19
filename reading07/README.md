Reading 07
==========

Activity 1
==========

1. The read_numbers function counts the number of integers inputted into the program. It dos this using the scanf function to only count until the pointer does not reach the EOF and only points to integers. Additionally, the size_t i ensures that the array stays in bounds. The & in front of the numbers[i] gets the address of the ith index and gives it the value of the read integer. EOF is the end of file constant that designates when the end of input has been reached. 

2. No this code would not work because the sizeof function returns the number of elements times the size of the variable type. In order to get the accurate number of elements, one must divide the size of the entire array by the size of an individual element. 


Activity 2
==========

1. The cat.c file does not parse tht ecommand line by removing argumnets as it goes, instead it increments the index number of argv and uses a pointer to point to the string value of each argument. In this way the cat.c program just moves down the arguments array and does not modify as cat.py does. 

2. The code parses the remaining arguments of the code to get the pathnames of the file. The char *path pointer will point to the reamining arguments starting where the code left off after the flags. If there is a blank argumnet, determined by comparing the path pointer to the "-" then the program will take in standard input for the files. This continutes until there are no more file arguments.

3. The cat_stream reads in characters from input  using fgets until end of line or the end of the file is reched. If the end of the line is reached it is stored in a buffer. Then fputs takes the buffer and sends it to standard out.

4. The cat_file function works to open and read a file given by the specified path. If the file is null, the if statement will tell the user that opening the file resulted in error. The output message includes the strerror which has the message associated with the error at the corresponding errno, or error number. 

