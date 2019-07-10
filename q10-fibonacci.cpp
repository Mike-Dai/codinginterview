/* 
 * my version
 * too much repetitive computation
 * low efficiency
 */
long long Fibonacci(unsigned int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else {
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

/* 
 * official answer
 * save the intermediate result
 * bottom-up
 * O(n)
 */
long long Fibonacci(unsigned int n) {
	int result[2] = {0, 1};
	if (n < 2) {
		return result[n];
	}

	long long FibN = 0;
	long long FibMinusOne = 1;
	long long FibMinusTwo = 0;
	for (int i = 2; i <= n; ++i) {
		FibN = FibMinusOne + FibMinusTwo;
		FibMinusTwo = FibMinusOne;
		FibMinusOne = FibN;
	}
	return FibN;
}