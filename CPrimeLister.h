// This is the header file for the CPrimeLister struct and helpers.

#include <math.h>
#include <stdio.h>

// Initializes thePrimes. Returns 0 if malloc fails
int initThePrimes(); 

// Builds CPrimeLister
// Adds the next prime number to the list. Returns prime, or 0 if malloc fails.
unsigned int nextPrime();
// Finds all primes less than ceiling
unsigned int findPrimesUntil(unsigned int ceiling);

// Deleter
// Removes last prime found
int removePrime();

// Sums all the primes that have been found
unsigned long long sumThePrimes();

// Support/debugging functions
// Prints thePrimes, continues until stopAt or prints all if stopAt is negative
void printThePrimes(int stopAt);
void printPrimeRange(int start, int stop);
