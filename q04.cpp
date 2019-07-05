/* 
 * my version 
 * cannot be compatible with 1 dimension array
 * need to consider invalid argument
 */
bool find(int** numbers, int row, int col, int num) {
	int i = 0, j = col - 1;
	while (i < row && j >= 0) {
		if (numbers[i][j] = num) {
			return true;
		}
		else if (numbers[i][j] > num) {
			j--;
		}
		else {
			i++;
		}
	}
	return false;
}

/*
 * answer
 */
bool Find(int* matrix, int row, int col, int number) {
	bool found = false;
	if (matrix != nullptr && row > 0 && col > 0) {
		int i = 0, j = col - 1;
		while (i < row && j >= 0) {
			if (matrix[i * col + j] = num) {
				found = true;
				break;
			}
			else if (numbers[i * col + j] > num) {
				j--;
			}
			else {
				i++;
			}
		}
	}
	return found;
}