/*
 * my version 
 * bug: doesn't prevent repetitive path
 *      infinite loop, should end at '\0'
 * better: see 2d matrix as 1d array
 */

bool hasPath(char** matrix, int rows, int cols, char* str) {
	if (matrix == nullptr || rows <= 0 || cols <= 0 || str[0] == '\0') {
		return false;
	}
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (matrix[i][j] == str[0]) {
				if (findPath(matrix, rows, cols, i, j, str + 1)) return true;
				else continue;
			}
		}
	}
	return false;
}

bool findPath(char** matrix, int rows, int cols, int row, int col, char* str) {
	int result = 0;
	char* str1 = str + 1;
	if (row > 0) {
		if (matrix[row - 1][col] == str[0]) {
			if (findPath(matrix, rows, cols, row - 1, col, str1)) return true;
		}
	}
	if (row < rows - 1) {
		if (matrix[row + 1][col] == str[0]) {
			if (findPath(matrix, rows, cols, row + 1, col, str1)) return true;
		}
	}
	if (col > 0) {
		if (matrix[row][col - 1] == str[0]) {
			if (findPath(matrix, rows, cols, row, col - 1, str1)) return true;
		}
	}
	if (col < cols) {
		if (matrix[row][col + 1] == str[0]) {
			if (findPath(matrix, rows, cols, row, col + 1, str1)) return true;
		}
	}
	return false;
}

/* 
 * official answer
 */

bool hasPath(char* matrix, int rows, int cols, char* str) {
	if (matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr) {
		return false;
	}
	bool visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);

	int pathLength = 0;
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited)) {
				return true;
			}
		}
	}
	delete[] visited;
	return false;
}

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, 
				char* str, int& pathLength, bool* visited)
{
	if (str[pathLength] == '\0') {
		return true;
	}
	bool hasPath = false;
	if (row >= 0 && row < rows && col >= 0 && col < cols && 
		matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])
	{
		++pathLength;
	}	
	visited[row * cols + col] = true;

	hasPath = hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
			||hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited)
			||hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
			||hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited);
	if (!hasPath) {
		--pathLength;
		visited[row * cols + col] = false;
	}
	return hasPath;
}