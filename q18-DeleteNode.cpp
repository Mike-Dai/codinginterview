struct ListNode {
	int       m_pValue;
	ListNode* m_pNext;
};

/*
 * my version
 * wrong: ignore one node condition (head == tail)
 *        ignore invalid arguments
 * 		  delete head and delete normal node are same
 *        delete tail need O(n)
 *        delete first, then set it to nullptr
 */
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
	ListNode* node = *pListHead;
	if (pToBeDeleted->m_pNext == nullptr) {
		pToBeDeleted = nullptr;
	}
	else if (pToBeDeleted == *pListHead) {
		*pListHead = node->m_pNext;
		node->m_pNext = nullptr;
	}
	else {
		node = pToBeDeleted->m_pNext;
		pToBeDeleted->m_pNext = node->m_pNext;
		pToBeDeleted->m_pValue = node->m_pValue;
		node->m_pNext = nullptr;
	}
	return;
}

/* 
 * official answer
 */
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
	if (!pListHead || !pToBeDeleted) {
		return;
	}
	ListNode* node = nullptr;
	if (pToBeDeleted->m_pNext != nullptr) {
		node = pToBeDeleted->m_pNext;
		pToBeDeleted->m_pNext = node->m_pNext;
		pToBeDeleted->m_pValue = node->m_pValue;
		delete node;
		node = nullptr;
	}
	else {              				  /* is tail */
		if (*pListHead = pToBeDeleted) {  /* only one node */
			delete pToBeDeleted;
			pToBeDeleted = nullptr;
			*pListHead = nullptr;         /* set head nullptr */
		}
		else {							  /* is tail */
			node = *pListHead;
			while (node->m_pNext != nullptr) {
				node = node->m_pNext;
			}
			node->m_pNext = nullptr;
			delete pToBeDeleted;
			pToBeDeleted = nullptr;
		}
	}
}