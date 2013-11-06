#include <stdio.h>
#include <stdlib.h>
#include "CPrimeLister.h"

int main(int argc, char *argv[])
{
	unsigned int temp;
	unsigned long long theSum; // The sum
	if (!(temp = initThePrimes())) {
		return 0;
	}
	
	
	while ((temp = nextPrime()) < 2000000) {
		if (!temp) {
			return 0;
		}
	//	printf("%d\n", thePrimes.primeCount);
	}
	
	//printPrimeRange(3, 10);
	
	
	theSum = sumThePrimes();
	if (theSum < 0) {
		system("PAUSE");
		return 0;
	}
	theSum -= thePrimes.biggestPrime;
	printf("Sum = %x\n", theSum);
	printf("Sum = %x\n", theSum >> 32);
	printf("PrimeCount = %d\n", thePrimes.primeCount);
	printf("BiggestPrime = %d\n", thePrimes.biggestPrime);
	printf("BiggestPrime * primeCount = %d\n", thePrimes.biggestPrime * thePrimes.primeCount);
	
	
	system("PAUSE");
	return 0;
}
