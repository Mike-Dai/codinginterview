/*
 * official answer
 */
bool match(char* str, char* pattern) {
	if (str == nullptr || pattern == nullptr) {
		return false;
	}
	return matchCore(str, pattern);
}

bool matchCore(char* str, char* pattern) {
	if (*str == '\0' && *pattern == '\0') {
		return true;
	}
	if (*str != '\0' && *pattern == 0) {
		return false;
	}
	if (*(pattern + 1) == '*') {
		if (*pattern == *str || *pattern == '.' && *str != '\0') {
			return matchCore(str + 1, pattern)      /* stay on the current state */
				 ||matchCore(str + 1, pattern + 2)  /* move on the next state */
				 ||matchCore(str, pattern + 2);     /* ignore a '*' */
		}
		else {
			return matchCore(str, pattern + 2);     /* ignore a '*' */
		}
	}
	if (*pattern == *str || *pattern == '.' && *str != '\0') {
		return matchCore(str + 1, pattern + 1);
	}
	return false;
}