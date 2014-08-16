This directory is for the programming exercises from Column 1 of _Programming Pearls_.

This problem here is to sort a file of toll-free (800) numbers. The author describes using a bit vector as the data structure to store and sort the numbers in memory.

The bit_vector class works by creating a vector of 10000000 bits and initializing them all to 0. Then, a file of random numbers on each line is read and sets the corresponding bit in the vector. After this is done, the vector is iterated over and writes each index that has a set bit back to the file.

Next, the author gives you the contstraint of only being able to use 1MB of memory. This requires a 2 pass algorithm, which is implemented in the bit_vector_2pass class.

Test data is a randomly generated list of integers with possible values 0 - 9999999 (the possible range of values for a 7-digit phone number). In test.cc I generate 1000000numbers for each test. The executable also allows parameters for the number of iterations for each test and the path to the file that you wish to use for testing. In my tests, I ran 5 iterations of each test, using the file phone_numbers.dat from the root of the project using the command:
```./bin/pp_col1 5 ./pp_col1/phone_numbers.dat```
