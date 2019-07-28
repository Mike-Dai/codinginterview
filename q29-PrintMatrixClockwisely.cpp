/*
 * official answer
 */
void PrintMatrixClockwisely(int** numbers, int rows, int columns) {
	if (numbers == nullptr || rows <= 0 || columns <= 0) {
		return;
	}
	int start = 0;

	while (start < rows / 2 && start < columns / 2) {
		PrintMatrixInCircle(numbers, rows, columns, start);
		start++;
	}
}

void PrintMatrixInCircle(int** numbers, int rows, int columns, int start) {
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;
	for (int i = start; i <= endX; ++i) {
		int number = numbers[start][i];
		Print(number);
	}
	if (endY > start) {
		for (int i = start + 1; i <= endY; ++i) {
			int number = numbers[i][endX];
			Print(number);
		}
	}
	if (endY > start && endX > start) {
		for (int i = endX - 1; i >= start; --i) {
			int number = numbers[endY][i];
			Print(number);
		}
	}
	if (endX > start && endY > start + 1) {
		for (int i = endY - 1; i >= start + 1; --i) {
			int number = numbers[i][start];
			Print(number);
		}
	}
}

void Print(int number) {
	cout << number << " ";
}