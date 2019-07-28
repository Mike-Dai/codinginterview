struct BinaryTreeNode {
	int             m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/* 
 * my version
 */
bool isSymmetrical(BinaryTreeNode* root) {
	if (root == nullptr) {
		return false;
	}
	
	return isSymmetricalCore(root->m_pLeft, root->m_pRight);
}

bool isSymmetricalCore(BinaryTreeNode* left, BinaryTreeNode* right) {
	if (left == nullptr && right == nullptr) {
		return true;
	}
	else if (left != nullptr && right != nullptr) {
		if (left->m_nValue == right->m_nValue) {
			return isSymmetricalCore(left->m_pLeft, right->m_pRight)
				 &&isSymmetricalCore(left->m_pRight, right->m_pLeft);
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}