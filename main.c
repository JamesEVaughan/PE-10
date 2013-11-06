#include <stdio.h>
#include <stdlib.h>
#include "CPrimeLister.h"

int main(int argc, char *argv[])
{
	unsigned int temp;
	unsigned long long theSum; // The sum
	if (temp = initThePrimes() == 0) {
		return 0;
	}
	
	/* Previous incarnation had direct access to struct thePrimes. Removed user
	*	user access and added findPrimesUntil() to handle this problem. 
	while ((temp = nextPrime()) < 2000000) {
		if (!temp) {
			return 0;
		}
	//	printf("%d\n", thePrimes.primeCount);
	}
	*/
	//printPrimeRange(3, 10);
	
	findPrimesUntil(2000000);
	theSum = sumThePrimes();
	if (theSum < 0) {
		system("PAUSE");
		return 0;
	}
	printf("Sum = %I64u\n", theSum);
	
	
	system("PAUSE");
	return 0;
}
