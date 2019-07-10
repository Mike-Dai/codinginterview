int Min(int* array, int length) {
	if (array == nullptr || length <= 0) {
		return NULL;
	}
	if (array[0] < array[length - 1]) {
		return array[0];
	}
	int low = 0, high = length - 1, middle;
	middle = (low + high) / 2;
	while (middle != high && middle != low) {
		if (array[low] > array[middle]) {
			high = middle - 1;
			middle = (low + high) / 2;
		}
		else if (array[middle] > array[high]) {
			low = middle + 1;
			middle = (low + high) / 2;
		}
	}
	if (array[low] > array[middle]) {
		return array[middle];
	}
	else if (array[middle] > array[high]) {
		return array[high];
	}
}