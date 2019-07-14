template <typename T>
class CQueue {
public:
	CQueue(void);
	~CQueue(void);
	void appendTail(const T& node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};

void CQueue::appendTail(const T& node) {
	stack1.push(node);
}

/* 
 * my version
 * bug: stack::pop return none!
 * should return stack::top()
 */
T CQueue::deleteHead() {
	if (stack1.empty() && stack2.empty()) {
		return NULL;
	}
	if (stack2.empty()) {
		while (!stack1.empty()) {
			T node = stack1.pop();
			stack2.push(node);
		}
		return stack2.pop();
	}
	else {
		return stack2.pop();
	}
}

/* 
 * official answer
 */
T CQueue::deleteHead() {
	if (stack2.size() <= 0) {
		while (stack1.size() > 0) {
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}3
	}
	if (stack2.size() == 0) {
		throw new exception("Queue is empty");
	}
	T head = stack2.top();
	stack2.pop();
	return head;
}