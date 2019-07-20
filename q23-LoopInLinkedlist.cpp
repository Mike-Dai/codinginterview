struct ListNode {
	int m_pValue;
	ListNode* m_pNext;
};

int MeetingNode(ListNode* pHead) {
	ListNode *pAhead = *pBehind = pHead;
	while (pAhead->m_pNext != nullptr && pAhead->m_pNext->m_pNext != nullptr) {
		pAhead = pAhead->m_pNext->m_pNext;
		pBehind = pBehind->m_pNext;
		if (pAhead == pBehind) {
			int n = 1;
			pAhead = pAhead->m_pNext;
			while (pAhead != pBehind) {
				pAhead = pAhead->m_pNext;
				n++;
			}
			return n;
		}
	}
	return 0;
}

ListNode* EntryNodeOfLoop(ListNode* pHead) {
	if (pHead == nullptr) {
		return nullptr;
	}
	int n;
	if ((n = MeetingNode(pHead)) != 0) {
		ListNode *pAhead = *pBehind = pHead;
		while (n > 0) {
			n--;
			pAhead = pAhead->m_pNext;
		}
		while (pAhead != pBehind) {
			pAhead = pAhead->m_pNext;
			pBehind = pBehind->m_pNext;
		}
		return pAhead;
	}
	return nullptr;
 }