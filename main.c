#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void green() {
	printf("\033[1;32m");
}

void reset() {
	printf("\033[0m");
}

void help(char *packagename) {
	printf("Random Password Generator\nUsage: %s -l <length>\nexample: %s -l 25\n", packagename, packagename);
}

void passgen(int passlen) {
	int randomizer = 0;
	srand((unsigned int) (time(NULL)));

	// Chacters in password
	char numbers[] = "0987654321";
	char letter[] = "qwertyuiopasdfghjklzxcvbnm";
	char LETTER[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
	char symbols[] = "!@#$%^&*/|";

	char password[passlen];

	randomizer = rand() % 4;

	printf("Password: ");

	for (int i = 0; i < passlen; i++) {
		if (randomizer == 1) {
			password[i] = numbers[rand() % 10];
			randomizer = rand() %  4;
			green();
			printf("%c", password[i]);
			reset();
		} else if (randomizer == 2) {
			password[i] = symbols[rand() % 10];
			randomizer = rand() % 4;
			green();
			printf("%c", password[i]);
			reset();
		} else if (randomizer == 3) {
			password[i] = LETTER[rand() % 26];
			randomizer = rand() % 4;
			green();
			printf("%c", password[i]);
			reset();
		} else {
			password[i] = letter[rand() % 26];
			randomizer = rand() % 4;
			green();
			printf("%c", password[i]);
			reset();
		}
	}
	printf("\n\n");
}

// the main function
int main(int argc, char *argv[]) {

	char *flag = "-l";

	if (argc == 3) {
		if (strcmp(argv[1], flag) == 0) {
			int passlen = atoi(argv[2]);
			passgen(passlen);
		} else {
			help(argv[0]);
			exit(0);
		}
	} else{
		help(argv[0]);
		exit(0);
	}

	return 0;
}
