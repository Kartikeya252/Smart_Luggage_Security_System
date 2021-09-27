#define _CRT_SECURE_NO_DEPRECATE 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

char pass[11];

void auto_passgeneration();
int check_passintegrity(char password[11]);
                                                                                       
int main() {

	char c[4];
	printf("Do you want to assign password manually or automatic for your luggage\n");
	printf("Type:\nyes --> for automatic password generation\nno  --> for manual generation\n");
	scanf("%s", c);

	if (strcmp(c, "yes") == 0) {
		auto_passgeneration();
		printf("Your generated password is %s\n", pass);
	}

	else if (strcmp(c, "no") == 0) {
			printf("Please make your password:\n");
			scanf("%s", pass);
			int check = check_passintegrity(pass);
			while (check != 0) {
				printf("Sorry password integrity is not matched\n");
				printf("Make sure you have inserted letters(upper as well as lowercase), numbers as well as special characters\n");
				scanf("%s", pass);
				int check = check_passintegrity(pass);
			}
		}

	else {
		printf("Please answer in yes or no only.\n");
		exit(1);
	}

	char pass2[11];
	printf("Enter the password to unlock your baggage:\n");
	scanf("%s", pass2);
	int pass_check = strcmp(pass, pass2);

	if (pass_check == 0) {
		printf("Entered password is correct.\n");
		printf("Your luggage is now unlocked.\n");
	}

	else {
		int temp = 3;
		char pass_temp[11];
		for (int i = 0; i < 4; i++) {
			printf("\nSorry ! password is not correct.\n");
			printf("Number of tries available : %d\n", temp--);
			printf("Please re-enter password:\n");
			scanf("%s", pass_temp);
			if (strcmp(pass_temp, pass) == 0)
				break;
		}
		if (temp < 0) {
			printf("Sorry! all tries are exhausted!!\n");
			printf("You can't unlock your luggage now!\n");
		}
		else
			printf("Your luggage is now unlocked.\n");
	}
}

void auto_passgeneration() {
	char s_letters[27] = "abcdefghijklmnopqrstuvwxyz";
	char c_letters[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char numbers[11] = "1234567890";
	char symbols[9] = "!@#$%^&*";
	srand((unsigned int)(time(NULL)));
	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			pass[i] = c_letters[rand() % 26];
		}
		else if (i == 1) {
			pass[i] = numbers[rand() % 10];
		}
		else if (i == 2) {
			pass[i] = symbols[rand() % 8];
		}
		else {
			pass[i] = s_letters[rand() % 26];
		}
	}
}

int check_passintegrity(char password[11]) {

	int y = 0, n = 1, counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0;
	if (strlen(password) != 10)
		return n;
	for (int i = 0; i < 10; i++) {
		if ( password[i] >= 65 && password[i] <= 90) 
			counter1++;
		else if (97 <= password[i] && password[i] <= 122)
			counter2++;
		else if (48 <= password[i] && password[i] <= 57)
			counter3++;
		else 
			counter4++;
	}
	
	if ((counter1 > 0) && (counter2 > 0) && (counter3 > 0) && (counter4 > 0)) {
		
		return y;
	}
	else
		return n;
}
