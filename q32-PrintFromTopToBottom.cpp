struct BinaryTreeNode{
	int             m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/*
 * official answer
 */
void PrintFromTopToBottom(BinaryTreeNode* root) {
	if (root == nullptr) {
		return;
	}
	deque<BinaryTreeNode*> data;
	BinaryTreeNode* curr;
	data.push_back(root);
	while (!data.empty()) {
		curr = data.front();
		cout << curr->m_nValue;
		if (curr->m_pLeft != nullptr) {
			data.push_back(curr->m_pLeft);
		}
		if (curr->m_pRight != nullptr) {
			data.push_back(curr->m_pRight);
		}
		data.pop_front();
	}
}