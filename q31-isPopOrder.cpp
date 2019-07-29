/*
 * my version
 * wrong
 */
bool isPopOrder(const int* pPush, const int* pPop, int nLength) {
	if (pPush == nullptr || pPop == nullptr || nLength == 1) {
		return false;
	}
	int* push = pPush;
	int* pop = pPop;
	stack<int> data;
	int number1 = 0;
	int number2 = 0;
	while (1) {
		if (number1 == nLength && number2 == nLength) {
			return true;
		}
		if (data.size() == 0) {
			data.push(*push);
			push++;
		}
		else {
			while (data.top() != *pop) {
				data.push(*push);
				push++;
			}
			data.pop();
			pop++;
			number++;
		}
	}
}

/*
 * official answer
 */
bool isPopOrder(const int* pPush, const int* pPop, int nLength) {
	bool pPossible = false;
	if (pPush != nullptr && pPop != nullptr && nLength > 0) {
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;
		stack<int> stackData;

		while (pNextPop - pPop < nLength) {
			while (stackData.empty() || stackData.top() != *pNextPop) {
				if (pNextPush - pPush >= nLength) {
					break;
				}
				stackData.push(*pNextPush);
				pNextPush++;
			}
			if (stackData.top() != *pNextPop) {
				break;
			}
			stackData.pop();
			pNextPop++;
		}
		if (stackData.empty() && pNextPop - pPop == nLength) {
			pPossible = true;
		} 
	}
	return pPossible;
}