Reading 08
==========

1. 1) 4 bytes
   2) 20 bytes
   3) 5 bytes
   4) 16 bytes
   5) 8 bytes
   6) 24 bytes
   7) 168 bytes
   8) 88 bytes

2. The memory error in Task 3 was that there was not enough memory allocated for the array of random numbers. This is because the malloc sis not used sizeof to allocate the memory. I fixed this by implementing the sizeof function. The memory error in Task 4 related to the memory not being freed properly. I fixed this by adding a free memory option before the if statement returned true. In this way if a duplicate was found, then the memory would be freed. Previously, the function would have just exited without the memory being freed becuas ethe free memory thing was outside teh for loop.
   
