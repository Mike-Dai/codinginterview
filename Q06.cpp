struct ListNode {
	int m_nKey;
	ListNode *m_pNext;
};

/*
 * it's OK
 * but a long linked list will cause a deep recursive call
 */
void PrintListReversingly_Recursively(ListNode* pHead) {
	if (pHead != nullptr) {
		if (pHead->m_pNext == nullptr) {
			printf("%d ", pHead->m_nKey);
			return;
		}
		else {
			PrintListReversingly_Recursively(pHead->m_pNext);
			printf("%d ", pHead->m_nKey);
		}
	}
}

/* 
 * stack version
 * but pHead should not be modified
 */
void PrintListReversingly_Iteratively(ListNode* pHead) {
	std::stack<ListNode*> nodes;
	while (pHead != nullptr) {
		nodes.push(pHead);
		pHead = pHead->m_pNext;
	}

	while (!empty(nodes)) {         /* wrong! */
		printf("%d\t", nodes.top->m_nKey);  /* top() */
		nodes.pop();
	}
}

/* 
 * official answer 
 */
void PrintListReversingly_Iteratively(ListNode* pHead) {
	std::stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty()) {
		pNode = nodes.top();
		printf("%d\t", pNode->m_nKey);
		nodes.pop();
	}
}