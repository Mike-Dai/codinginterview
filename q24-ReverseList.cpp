struct ListNode {
	int m_nKey;
	ListNode* m_pNext;
};

ListNode* ReverseList(ListNode* pHead) {
	if (pHead == nullptr) {
		return nullptr;
	}
	ListNode *prev, *curr, *next;
	prev = nullptr;
	curr = pHead;
	next = pHead->m_pNext;
	while (next != nullptr) {
		curr->m_pNext = prev;
		prev = curr;
		curr = next;
		next = next->m_pNext;
	}
	curr->m_pNext = prev;
	return curr;
}