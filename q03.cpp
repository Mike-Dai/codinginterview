/*
 * my version1
 * space complexity O(n)
 * should consider no dupilcation case
 */
int duplicate1(int* array, int size) {
	int count[size] = 0;
	for (int i = 0; i < size; ++i) {
		count[array[i]]++;
		if (count[array[i]] > 1) {
			return array[i];
		}
	}
}

/* 
 * my version2
 * should consider invalid argument
 * may need more than one swap
 */
bool duplicate2(int* array, int size, int* result) {
	for (int i = 0; i < size; ++i) {
		int m = array[i];
		if (m == i) continue;
		else if (m != i) {
			if (array[i] == array[m]) {
				result = array[i];
				return true;
			}
			else {
				int t = array[i];
				array[i] = array[m];
				array[m] = t;
			}
		}
	}
	return false;
}

/* 
 * answer
 * time complexity: O(n)
 * space complexity: O(1)
 */
bool duplicate(int numbers[], int length, int* duplication) {
	if (numbers == nullptr || lenght <= 0) {
		return false;
	} 
	for (int i = 0; i < length; ++i) {
		if (numbers[i] < 0 || numbers[i] > length - 1) {
			return false;
		}
	}
	for (int i = 0; i < length; ++i) {
		while (numbers[i] != i) {
			if (numbers[i] == numbers[numbers[i]]) {
				duplication = numbers[i];
				return true;
			}
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}