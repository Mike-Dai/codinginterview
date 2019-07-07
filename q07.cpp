struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/* 
 * official answer 
 */
BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
	if (preorder == nullptr || inorder == nullptr || length <= 0) {
		return nullptr;
	}
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder,
							  int* startInorder,  int* endInorder)
{
	/* the first element in preorder is root */
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	if (startPreorder == endPreorder) {
		if (startInorder == endInorder && *startPreorder == *startInorder) {
			return root;
		}
		else {
			throw std::exception("invalid input");
		}
	}
	/* find root in inorder */
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue) {
		++rootInorder;
	}	

	if (rootInorder == endInorder && *rootInorder != rootValue) {
		throw std::exception("invalid input");
	}

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0) {                              /* construct left tree */
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd,
						startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder) {    /* construct right tree */
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
						rootInorder + 1, endInorder);
	}
	return root;
}