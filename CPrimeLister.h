// This is the header file for the CPrimeLister struct and helpers.

#include <math.h>
#include <stdio.h>

// This is the individaul nodes in CPrimeLister
struct CPrimeNode {
       unsigned int prime;
       struct CPrimeNode* next;
};

// This is a singly linked list head node for CPrimeLister
struct CPrimeLister {
       unsigned int biggestPrime;  // Biggest prime found
       unsigned int primeCount;    // Number of primes found
       unsigned int curRoot;       // The root to check against in NextPrime()
       struct CPrimeNode* first;          // First node in the list
       struct CPrimeNode* last;           // Last node in the list
} thePrimes;

// Initializes thePrimes. Returns 0 if malloc fails
unsigned int initThePrimes(); 

// Adds the next prime number to the list. Returns prime, or 0 if malloc fails.
unsigned int nextPrime();

unsigned long long sumThePrimes();

// Support/debugging functions
// Prints thePrimes, continues until stopAt or prints all if stopAt is negative
void printThePrimes(int stopAt);
void printPrimeRange(int start, int stop);
