/*
 * my version
 */
void ReorderOddEven(int *pData, unsigned int length) {
	if (pData == nullptr || length <= 1) {
		return;
	}
	int *p1, *p2;                    /* try to use clear name */
	p1 = pData;
	p2 = pData + length - 1;
	while (p1 < p2) {
		if (*p1 % 2 == 0) {          /* better: use bit operation */
			while (*p2 % 2 != 1) { 
				--p2;
			}
			int temp = *p1;
			*p1 = *p2;
			*p2 = temp;              /* forget forward p1 */
		}
	}
}

/*
 * official answer
 */
void ReorderOddEven(int *pData, unsigned int length) {
	if (pData == nullptr || length == 0) {
		return;
	}
	int *pBegin, *pEnd;
	pBegin = pData;
	pEnd = pData + length - 1;
	while (pBegin < pEnd) {
		while (pBegin < pEnd   && (*pBegin & 0x1) != 0) {
			pBegin++;
		}
		while (pEnd   > pBegin && (*pEnd   & 0x1) != 1) {
			pEnd--;
		}
		if (pBegin < pEnd) {
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}