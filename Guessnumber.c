#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>



int hitNum;
int blowNum;
char randomNum[16];
char randomNum2[16];

int GetValue(char c) {
	int i = c - 48;
	if (i > 9 || i < 0) return 0;
	else return i;
}

//Create random number
void createRandomNumber(char num[]) {
	int i = 0;

	int j,l;
	int sum;
	time_t sec;
	char temp;

	for (i = 0; i < 3; i++) {
		for (j = i; j < 4; j++) {
			if (num[i] < num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	int k = 3;
	for (i = 0; i < 4; i++) {
		temp = randomNum[i];
		randomNum[i] = num[i];
		num[i] = temp;
	}
	j = 0;
	for (i = 0; i < 3; i++) {
		for (k = 3; k > i; k--) {
			sum = (GetValue(randomNum[i]) + GetValue(randomNum[k-1])) % 7 +1;
			if (sum > 10) sum = sum - 10;
			if (sum > 20) sum = sum - 20;
			randomNum2[j] = sum + 48;
			j++;
		}
	}
	for (i = 4; i < 16; i++) {
		randomNum2[i] = '\0';
	}
}

//Define a valid number
int isValidNumber(char num[]) {
	int i;
	int j;
	int count;
	count = 0;
	for (i = 0; i < 4; i++) {
		for (j = i + 1; j < 4; j++) {
			if (num[i] == num[j]) {
				count = 1;
			}
		}
	}
	return count;
}

//Is the guess number is match with the target number?
int isMatch(char target[], char num[]) {
	int i;
	hitNum = 0;
	blowNum = 0;
	for (i = 0; i < 4; i++) {
		if (target[i] == num[i]) {
			hitNum++;
		}
	}
	if (hitNum == 4) {
		return 1;
	}
	else {
		return 0;
	}

}

//main
int main() {

	int i, count2;

	char Targetnum[16];
	char inputNum[16];
	char gueNum[16];

	// printf("Guess number: %s \n", inputNum);
	// printf("Random number: %s \n", randomNum2);
	printf("Guess number: "); //Player will input 4 digits number
	scanf("%s", inputNum);
	for (i = 0; i < 15; i++) {
		gueNum[i] = inputNum[i];
	}
	createRandomNumber(gueNum);


	count2 = 1;
	while (count2 == 1) {
		
		if (isValidNumber(inputNum) == 1) {
			printf("Invalid number, Please try again!!! \n");
			scanf("%s", inputNum);
		}
		else if (isValidNumber(inputNum) == 0) {
			if (isMatch(randomNum2, inputNum) == 1) {
				blowNum = 4 - hitNum;
				printf("HIT: %i \n", hitNum);
				printf("BLOW: %i \n", blowNum);
				printf("Congratulation!!! Your are right! \n\n");
				printf("Target number is: %s  \n", randomNum2);
				count2 = 0;
			}
			else if (isMatch(randomNum2, inputNum) == 0) {
				blowNum = 4 - hitNum;
				printf("HIT: %i \n", hitNum);
				printf("BLOW: %i \n", blowNum);
				printf("Please try again!!! \n\n");
				printf("GuessNumber: ");
				scanf("%s", inputNum);
			}
		}
	}

	return 0;
}




