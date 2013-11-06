// This is the implementation file for CPrimeLister and helper functions.

#include "CPrimeLister.h"

// Constants and defines

// Helper funcions hidden from users.
int addNodeByValue(int value);
int isPrime(int value);

// And now, on with the show!
unsigned int initThePrimes() {
	unsigned int first[5] = {2, 3, 5, 7, 11};	// First 5 primes
	int i;										// For loop iterator
	
	// Initialize the head node values
	thePrimes.curRoot = 1;
	thePrimes.primeCount = 1;
	
	// Prime the Pump
	if (!(thePrimes.first = thePrimes.last = malloc(sizeof(struct CPrimeNode)))) {
		printf("%d\n", thePrimes.first);
		return 0;
	}
	thePrimes.first->prime = first[0];
	
	for (i = 1; i < 5; i++) {
		if (!(addNodeByValue(first[i]))) {
			return 0;
		}
		printf("%d\n", thePrimes.primeCount);
	}
	
	return 1;
}

int addNodeByValue(int value) {
	if (!(thePrimes.last->next = malloc(sizeof(struct CPrimeNode)))) {
		return 0;
	}
	// Reset thePrime to reflect changes
	thePrimes.last = thePrimes.last->next;
	thePrimes.last->prime = value;
	thePrimes.last->next = 0;
	thePrimes.biggestPrime = value;
	thePrimes.primeCount++;
	if (thePrimes.curRoot * thePrimes.curRoot < value) {
		thePrimes.curRoot++;
	}
	
	return thePrimes.last->prime;
}

void printThePrimes(int stopAt) {
	int i = 0;
	
	// Sanity check, has thePrimes been initialized?
	if (!(thePrimes.first)) {
		return;
	}
	
	struct CPrimeNode *cur = thePrimes.first;
	while ((stopAt < 0) || (i < stopAt)) {
		if (i > thePrimes.primeCount) {
			return;
		}
		
		printf("%3d: %10d\n", i, cur->prime);
		if (!(cur->next)) {
			return;
		}
		cur = cur->next;
		i++;
	}
}

unsigned int nextPrime() {
	unsigned int curNum = thePrimes.biggestPrime+2;
	unsigned int curSquare = thePrimes.curRoot * thePrimes.curRoot;
	struct CPrimeNode *newNode;
	
	while (!isPrime(curNum)) {
		curNum += 2;
		if (curNum > curSquare) {
			thePrimes.curRoot++;
		}
	}
	
	// Do we still have space?
	if (!(newNode = thePrimes.last->next = malloc(sizeof(struct CPrimeNode)))) {
		return 0;
	}
	
	newNode->prime = curNum;
	newNode->next = 0;
	thePrimes.last = newNode;
	thePrimes.primeCount +=1;
	thePrimes.biggestPrime = curNum;
	if (curNum > curSquare) {
		thePrimes.curRoot++;
	}
	
	return curNum;
}

int isPrime(int value) {
	struct CPrimeNode *curNode = thePrimes.first;
	int i;
	
	for (i = 0; i <= thePrimes.curRoot; i++) {
		if (!(value % curNode->prime)) {
			return 0;
		}
		
		curNode = curNode->next;
	}
	
	return 1;
}

unsigned long long sumThePrimes() {
	unsigned long long sum = 0;
	struct CPrimeNode *curNode = thePrimes.first;
	int i;
	
	printf("%d\n", thePrimes.primeCount);
	for (i = 0; i < thePrimes.primeCount; i++) {
		sum += (unsigned long long)(curNode->prime);
		curNode = curNode->next;
		//printf("After %6d primes, the sum is\n%d\n", i, sum); 
		
		if (sum < 0) {
			printf("%d\n", i);
			return -1;
		}
	}
	
	printf("%x\n", sum);
	printf("%x\n", sum >> 16);
	return sum;
}

void printPrimeRange(int start, int stop) {
	int i;
	struct CPrimeNode *cur = thePrimes.first;
	
	for (i = 0; i <=start; i++) {
		cur = cur->next;
	}
	
	for (;i<stop; i++) {
		printf("%6d: %10d\n", i, cur->prime);
		cur = cur->next;
	}
}
