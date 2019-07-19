struct ListNode {
	int m_pValue;
	ListNode* m_pNext;
};

/*
 * my version
 * bad: need twice traversal and O(n) space
 */
ListNode* FindKthToFail(ListNode* pListHead, unsigned int k) {
	if (pListHead == nullptr || k <= 0) {
		return nullptr;
	}
	stack<ListNode*> nodes;
	ListNode* curr = pListHead;
	while (curr != nullptr) {
		nodes.push(curr);
		curr = curr.m_pNext;
	}
	while (k > 1) {
		if (nodes.empty()) {
			return nullptr;
		}
		nodes.pop();
		k--;
	}
	if (nodes.empty()) {
		return nullptr;
	}
	return nodes.top();
}

/*
 * official answer
 */
ListNode* FindKthToFail(ListNode* pListHead, unsigned int k) {
	if (pListHead == nullptr || k <= 0) {
		return nullptr;
	}
	ListNode *pAhead = *pBehind = pListHead;
	while (k > 1) {
		pAhead = pAhead->m_pNext;
		if (pAhead == nullptr) {
			return nullptr;
		}
		k--;
	}
	while (pAhead->m_pNext != nullptr) {
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}
	return pBehind;
}