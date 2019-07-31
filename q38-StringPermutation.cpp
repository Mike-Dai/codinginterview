/*
 * official answer
 */
void Permutation(char* pStr) {
	if (pStr == nullptr) {
		return;
	}
	Permutation(pStr, pStr);
}

void Permutation(char* pStr, char* pBegin) {
	if (pBegin == '\0') {
		printf("%s\n", pStr);
	}
	else {
		char temp;
		for (char* pCh = pBegin; pCh != '\0'; ++pCh) {
			temp = *pBegin;
			*pBegin = *pCh;
			*pCh = temp;
			Permutation(pStr, pBegin + 1);
			temp = *pBegin;
			*pBegin = *pCh;
			*pCh = temp;
		}
	}
}