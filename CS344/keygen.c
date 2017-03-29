/***************************
 * Darlene Zouras
 * CS344  Winter 2017
 * Prog 4
 **************************/

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	// make sure there are at least two arguments
	// report error if there are otherwise
	if (argc < 2) {
		fprintf(stderr, "USAGE: keygen length\n");
		exit(1);
	}

	int keyLength = atoi(argv[1]);

	// generate that many random numbers (1 - 27)
	// write to stdout the corresponding letter
	int i, num;
	srand(time(NULL));
	for (i = 0; i < keyLength; i++) {
		num = 65 + rand() % (91 - 65);
		printf("%c", num);
	}	
	printf("\n");

	return 0;
}
