/* 
 * official answer1
 */
void Print1ToMaxOfNDigits(int n) {
	if (n <= 0) {
		return;
	}
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number)) {
		PrintNumber(number);
	}

	delete[] number;
}

bool Increment(char* number) {
	bool isOverFlow = false;
	int nTakeOver = 0;
	int length = strlen(number);
	for (int i = length - 1; i >= 0; --i) 
	{
		sum = number[i] - '0' + nTakeOver;
		if (i == length - 1) {
			sum++;
		}
		if (sum >= 10) {
			if (i == 0) {
				isOverFlow = true;
			}
			nTakeOver = 1;
			sum -= 10;
			number[i] = '0' + sum;
		}
		else {
			number[lenght] = '0' + sum;
			break;
		}
	}
	return isOverFlow;
}

void PrintNumber(char* number) {
	bool isBeginning0 = true;
	for (int i = 0; number[i] != '\0'; ++i) {
		if (isBeginning0 && number[i] != '0') {
			isBeginning0 = false;
		}
		if (!isBeginning0) {
			printf("%c", number[i]);
		}
	}
	printf("\t");
}

/*
 * official answer2
 */
void Print1ToMaxOfNDigits(int n) {
	if (n <= 0) {
		return;
	}
	char* number = new char[n + 1];
	number[n] = '\0';
	for (int i = 0; i < 10; ++i) {
		number[0] = '0' + i;
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}
	delete[] number;
}

Print1ToMaxOfNDigitsRecursively(char* number, int length, int index) {
	if (index == length - 1) {
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; ++i) {
		number[index + 1] = '0' + i;
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}