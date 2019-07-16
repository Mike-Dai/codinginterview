/*
 * offcial answer
 */
bool isNumeric(const char* str) {
	if (str == nullptr) {
		return false;
	}
	bool numeric = scanInterger(&str);
	if (*str == '.') {
		str++;
		numeric = scanUnsignedInterger(&str) || numeric;   /* ??? */
	}
	if (*str == 'e' || *str == 'E') {
		str++;
		numeric = numeric && scanInterger(&str);           /* ??? */
	}
	return numeric && *str == '\0';
}

bool scanUnsignedInterger(char** str) {
	const char* before = *str;
	while (**str != '\0' && **str >= '0' && **str <= '9') {
		(*str)++;
	}
	return *str > before;
}

bool scanInterger(char** str) {
	if (**str == '+' || **str == '-') {
		(*str)++;
	}
	return scanUnsignedInterger(str);
}