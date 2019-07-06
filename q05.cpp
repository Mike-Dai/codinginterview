/* 
 * my version1
 * should use char[]
 */
void replaceBlank1(string str) {
	for (int pos = 0; pos < str.size(); pos++) {
		if (str[pos] == ' ') {
			str.replace(pos, 3, "%20");
		}
	}
}

/*
 * my version2
 * should move the string once to avoid duplicate move
 */
void replaceBlank2(char string[], int length) {
	int tail = length - 1;
	for (int i = length - 1; i >= 0; --i) {
		if (string[i] == ' ') {
			for (int j = tail; j > i; --j) {
				string[j + 2] = string[j];
			}
			tail += 2;
			string[i] = '%';
			string[i+1] = '2';
			string[i+2] = '0';
		}
	}
}

/*
 * my version3
 * length refers to total space. It's not equal to original length
 * should consider invalid argument
 */
void ReplaceBlank(char string[], int length) {
	int blank = 0;
	for (int i = 0; i < length; ++i) {
		if (string[i] == ' ') ++blank;
	}
	char *p1 = string + length - 1;
	char *p2 = string + length - 1 + blank * 2;
	while (p1 >= string && p1 != p2) {
		if (*p1 != ' ') {
			*p2 = *p1;
			--p1;
			--p2;
		}
		else {
			--p1;
			*p2 = '0';
			--p2;
			*p2 = '2';
			--p2;
			*p2 = '%';
			--p2;
		}
	}
}

/* 
 * official answer
 */
void ReplaceBlank(char string[], int length) {
	if (string == nullptr || length <= 0) return;
	int originalLength = 0;
	int numberOfBlank = 0;
	while (string[i] != '\0') {
		++originalLength;
		if (string[i] == ' ') {
			++numberOfBlank;
		}
		++i;
	}

	int newLength = originalLength + numberOfBlank * 2;
	if (newLength > length) return;

	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
		if (string[indexOfOriginal] == ' ') {
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else {
			string[indexOfNew--] = string[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}