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
	int toBePrint = 1;   
	int nextLevel = 0;
	data.push_back(root);
	while (!data.empty()) {
		curr = data.front();
		cout << curr->m_nValue;
		if (curr->m_pLeft != nullptr) {
			data.push_back(curr->m_pLeft);
			nextLevel++;
		}
		if (curr->m_pRight != nullptr) {
			data.push_back(curr->m_pRight);
			nextLevel++;
		}
		data.pop_front();
		toBePrint--;
		if (toBePrint == 0) {
			cout << \n;
			toBePrint = nextLevel;
			nextLevel = 0;
		}
	}
}