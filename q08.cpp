struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};

/* 
 * my version
 * return once will be better
 */
BinaryTreeNode* GetNode(BinaryTreeNode* pNode) {
	BinaryTreeNode* node = pNode;
	/* have right tree */
	if (pNode->m_pRight != nullptr) {
		node = pNode->m_pRight;
		while (node->m_pLeft != nullptr) {
			node = node->m_pLeft;
		}
		return node;
	}
	/* doesn't have right tree */
	else if (pNode->m_pRight == nullptr) {
		/* pNode is left tree of its father */
		if (pNode->m_pParent->m_pLeft == pNode) {
			return pNode->m_pParent;
		}
		/* pNode is right tree of its father */
		else {
			while (1) {
				if (node->m_pParent->m_pLeft == node) {
					return node;
				}
				else if (node->m_pParent->m_pRight == node && node->m_pParent == nullptr) {  /* the root */
					return nullptr;
				}
				node = node->m_pParent;
			}
		}
	}
}