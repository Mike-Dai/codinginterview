int moveRange(int m, int n, int k) {
	if (m == 0 || n == 0 || k < 0) {
		return 0;
	}
	bool visited = new bool[m * n];
	memset(visited, 0, sizeof(visited));
	int count = moveRangeCore(m, n, 0, 0, k, &visited);
	delete[] visited;
	return count;
}

int moveRangeCore(int m, int n, int i, int j, int k, bool* visited) {
	int count = 0;
	if (i >= 0 && i < m && j >= 0 && j < n && visited[i * n + j] == false && sum(i) + sum(j) <= k) {
		visited[i * n + j] = true;
		count = 1 + moveRangeCore(m, n, i - 1, j, k, visited)
				  + moveRangeCore(m, n, i + 1, j, k, visited)
				  + moveRangeCore(m, n, i, j - 1, k, visited)
				  + moveRangeCore(m, n, i, j + 1, k, visited);
	} 
	return count;
}

int sum(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}