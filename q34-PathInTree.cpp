struct BinaryTreeNode {
	int             m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight; 
};

/*
 * official answer
 */
void FindPath(BinaryTreeNode* root, int expectedSum) {
	if (root == nullptr) {
		return;
	}
	vector<int> path;
	int currentSum = 0;
	FindPath(root, expectedSum, path, currentSum);
}

void FindPath(BinaryTreeNode* root, int expectedSum,
			vector<int>& path, int currentSum)
{
	path.push_back(root->m_nValue);
	currentSum += root->m_nValue;
	bool isLeaf = (root->m_pLeft == nullptr) && (root->m_pRight == nullptr);
	if (currentSum == expectedSum && isLeaf) {
		vector<int>::iterator iter = path.begin();
		for (; iter != path.end(); ++iter) {
			cout << *iter << " ";
		}
		cout << \n;
	}
	if (root->m_pLeft != nullptr) {
		FindPath(root->m_pLeft, expectedSum, path, currentSum);
	}
	if (root->m_pRight != nullptr) {
		FindPath(root->m_pRight, expectedSum, path, currentSum);
	}
	path.pop_back();
}