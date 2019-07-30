struct BinaryTreeNode{
	int             m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/*
 * my version
 * wrong
 */
void PrintTreesInZigzag(BinaryTreeNode* root) {
	if (root == nullptr) {
		return;
	}
	deque<BinaryTreeNode*> data;
	BinaryTreeNode* curr;
	int toBePrint = 1;   
	int nextLevel = 0;
	bool leftToRight = false;
	data.push_back(root);
	while (!data.empty()) {
		curr = data.front();
		cout << curr->m_nValue;
		if (leftToRight) {
			if (curr->m_pLeft != nullptr) {
				data.push_back(curr->m_pLeft);
				nextLevel++;
			}
			if (curr->m_pRight != nullptr) {
				data.push_back(curr->m_pRight);
				nextLevel++;
			}
		}
		else {
			if (curr->m_pRight != nullptr) {
				data.push_back(curr->m_pRight);
				nextLevel++;
			}
			if (curr->m_pLeft != nullptr) {
				data.push_back(curr->m_pLeft);
				nextLevel++;
			}
		}
		data.pop_front();
		toBePrint--;
		if (toBePrint == 0) {
			cout << \n;
			toBePrint = nextLevel;
			nextLevel = 0;
			leftToRight = !leftToRight;
		}
	}
}

/*
 * my version2
 * ugly
 */
void PrintTreesInZigzag(BinaryTreeNode* root) {
	if (root == nullptr) {
		return;
	}
	stack<BinaryTreeNode*> stack1, stack2;
	BinaryTreeNode* curr;
	int toBePrint = 1;   
	int nextLevel = 0;
	bool isEven = true;
	stack2.push(root);
	while (!stack1.empty() || !stack2.empty()) {
		if (isEven) {
			curr = stack2.top();
			if (curr->m_pLeft != nullptr) {
				stack1.push(curr->m_pLeft);
				nextLevel++;
			}
			if (curr->m_pRight != nullptr) {
				stack1.push(curr->m_pRight);
				nextLevel++;
			}
			stack2.pop();
		}
		else {
			curr = stack1.top();
			if (curr->m_pRight != nullptr) {
				stack2.push(curr->m_pRight);
				nextLevel++;
			}
			if (curr->m_pLeft != nullptr) {
				stack2.push(curr->m_pLeft);
				nextLevel++;
			}
			stack1.pop();
		}
		cout << curr->m_nValue;
		toBePrint--;
		if (toBePrint == 0) {
			cout << \n;
			toBePrint = nextLevel;
			nextLevel = 0;
			isEven = !isEven;
		}
	}
}

/*
 * official answer
 */
void PrintTreesInZigzag(BinaryTreeNode* root) {
	if (root == nullptr) {
		return;
	}
	stack<BinaryTreeNode*> level[2];
	int current = 0;
	int next = 1;
	BinaryTreeNode* curr;
	level[current].push(root);
	while (!level[0].empty() || !level[1].empty()) {
		curr = level[current].top();
		level[current].pop();
		cout << curr->m_nValue;
		if (current) {
			if (curr->m_pLeft != nullptr) {
				level[next].push(curr->m_pLeft);
			}
			if (curr->m_pRight != nullptr) {
				level[next].push(curr->m_pRight);
			}
		}
		else {
			if (curr->m_pRight != nullptr) {
				level[next].push(curr->m_pRight);
			}
			if (curr->m_pLeft != nullptr) {
				level[next].push(curr->m_pLeft);
			}
		}
		if (level[current].empty()) {
			cout << \n;
			current = 1 - current;
			next = 1 - next;
		}
	}
}