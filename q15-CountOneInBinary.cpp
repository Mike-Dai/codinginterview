/* 
 * my verison
 * "/" has lower efficiency than ">>"
 */
int count(int number) {
	int count = 0;
	if (number < 0) {
		count++;
		number = -number;
	}
	while (number > 0) {
		count += number % 2;
		number /= 2;
	}
	return number;
}

/*
 * official answer1
 * but need 32 loop for 32 bit interger
 */
int NumberOf1(int n) {
	int count = 0;
	unsigned int flag = 1;
	while (flag) {
		if (n & flag) {
			count++;
		}
		flag = flag << 1;
	}
	return count;
}

/* 
 * official answer2
 * only need x loop for x one
 */
int NumberOf1(int n) {
	int count = 0;
	while (n) {\
		count++;
		n = n & (n - 1);
	}
	return count;
}