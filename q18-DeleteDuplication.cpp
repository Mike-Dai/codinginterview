struct ListNode {
	int       m_pValue;
	ListNode* m_pNext;
};
/* 
 * my version
 * wrong: if two node duplicate, should delete both of them
 */
void deleteDuplication(ListNode** pHead) {
	if (pHead == nullptr) {        /* *pHead can also be nullptr */
		return;
	}
	ListNode* preNode = *pHead;
	if (preNode->m_pNext == nullptr) {
		return;
	}
	ListNode* node = preNode->m_pNext;
	while (node != nullptr) {
		if (node->m_pValue == preNode->m_pValue) {
			preNode->m_pNext = node->m_pNext;
			delete node;
			node = node->m_pNext;
		}
		else {
			preNode = node;
			node = node->m_pNext;
		}
	}
	return;
}

/*
 * official answer 
 */
void deleteDuplication(ListNode** pHead) {
	if (pHead == nullptr || *pHead == nullptr) {
		return;
	}
	ListNode* pPreNode = nullptr;
	ListNode* pNode = *pHead;
	while (pNode != nullptr) {
		ListNode* pNext = pNode->m_pNext;
		bool needDeleted = false;
		if (pNext != nullptr && pNode->m_pValue == pNext->m_pValue) {
			needDeleted = true;
		}
		if (!needDeleted) {
			pPreNode = pNode;
			pNode = pNext;
		}
		else {                          /* need delete */
			int value = pNode->m_pValue;
			ListNode* pToBeDel = pNode;
			while (pToBeDel != nullptr && pToBeDel->m_pValue == value) {
				pNext = pToBeDel->m_pNext;
				delete pToBeDel;
				pToBeDel = nullptr;
				pToBeDel = pNext;
			}
			if (pPreNode == nullptr) {  /* first node */
				*pHead = pNext;
			}
			else {                      /* middle node */
				pPreNode->m_pNext = pNext;
			}
			pNode = pNext;
		}
	}
}