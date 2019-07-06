/* 
 * my version 
 * compare the right top corner of partial matrix to the number
 * cannot be compatible with 1 dimension array
 * need to consider invalid argument
 */
bool find(int** numbers, int row, int col, int num) {
	int i = 0, j = col - 1;
	while (i < row && j >= 0) {
		if (numbers[i][j] = num) {
			return true;
		}
		else if (numbers[i][j] > num) {  /* if bigger, eliminate this column */
			j--;
		}
		else {                           /* if smaller, eliminate this row */
			i++;
		}
	}
	return false;
}

/*
 * answer
 * can also use the number in left bottom corner to compare 
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