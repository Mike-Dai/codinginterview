/*
 * official answer
 */
void Serialize(BinaryTreeNode* root, ostream& stream) {
	if (root == nullptr) {
		stream << "$,";
		return;
	}
	stream << root->m_nValue << ',';
	Serialize(root->m_pLeft, stream);
	Serialize(root->m_pRight, stream);
}

void Deserialize(BinaryTreeNode** root, istream& stream) {
	int number;
	if (ReadStream(stream, &number)) {
		*root = new BinaryTreeNode();
		(*root)->m_nValue = number;
		(*root)->m_pLeft = nullptr;
		(*root)->m_pRight = nullptr;
	}
	Deserialize(&((*root)->m_pLeft), stream);
	Deserialize(&((*root)->m_pRight), stream);
}