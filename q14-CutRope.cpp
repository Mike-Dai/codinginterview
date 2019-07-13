/* 
 * official answer
 */
int maxProductAfterCutting_solution1(int length) {
	if (length < 2) {
		return 0;
	}
	if (length == 2) {
		return 1;
	}
	if (length == 3) {
		return 2;
	}

	int* product = new product[length];
	product[0] = 0;
	product[1] = 1;
	product[2] = 2;
	product[3] = 3;
	int max = 0;
	for (int i = 4; i <= length; ++i) {
		max = 0;
		for (int j = 1; j <= i / 2; ++j) {
			int product = product[i] * product[i - j];
			if (product > max) {
				max = product;
			}
			product[i] = max;
		}
	}
	max = product[length];
	delete[] product;
	return max;
}