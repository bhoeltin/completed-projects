Reading 09
==========

1.  1) The size of s is 16 bytes and the size of u is 8 bytes. 
    2) The difference between and union a struct is that the union only reserves enough memory for its largest member while the struct allocates memory for each of its members.

2.  1) The program outputs "fate is inexorable!".
    2) The values in the string printed out our stored in the struct when they are assigned. However these are not the actual characters that are stored but their binary representation. This is the only way the computer understands data. Every value then in the struct is converted when casted.
    3) No matter what the type of variable being represented, it will always be represented in binary. Casting does this process of conversion.

3. 1) A collision happens when a function maps two very distinct inputs to the same output.
   2) With separate chainging, the data is separated into buckets that hold 0-1 entries that ash into the same location. The keys are evenly distributed as to make it efficient.
   3) Linear probing ensures that each key hashes into a position that is not already occupied. If a position is occupied, linear probing will look for the next available spot. Then when looking for the element later in the hash table, a hash code is used to look in one spot and if the element is not found there, it will compute new locations until it is found. 

4. h(x) = x % 10
   7 % 10 = 7
   3 % 10 = 3
   2 % 10 = 2
   78 % 10 = 8
   56 % 10 = 6
   72 % 10 = 2
   79 % 10 = 9
   68 % 10 = 8
   13 % 10 = 3
   14 % 10 = 4 

   1) | Bucket | Value |
      |--------|-------|
      |   0    |       |
      |   1    |       |
      |   2    |  2 72 |
      |   3    |  3 13 |
      |   4    |   14  |
      |   5    |       |
      |   6    |   56  |
      |   7    |   7   |
      |   8    | 78 68 |
      |   9    |   79  |
      |--------|-------|

   2) | Bucket | Value |
      |--------|-------|
      |   0    |   68  | 
      |   1    |   14  |
      |   2    |   2   |
      |   3    |   3   |
      |   4    |   72  |
      |   5    |   13  |
      |   6    |   56  |
      |   7    |   7   |
      |   8    |   78  |
      |   9    |   79  |
      |--------|-------|



