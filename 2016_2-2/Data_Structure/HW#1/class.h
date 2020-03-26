// å�� �ִ� �ڵ带 �ۼ��߱� ������, å�� �ߺ��Ǵ� �κ��� �ּ�ó���� �����ʾҽ��ϴ�.

template <class T>
void ChangeSizeID(T*&a, const int oldSize, const int newSize)
{
	if (newSize < 0) throw "New length must be >=0";

	T* temp = new T[newSize];
	int number;
	if (oldSize >= newSize)
		number = newSize;
	else
		number = oldSize;
	//copy(a, a + number, temp);
	delete[] a;
	a = temp;
}

template <class T>
class Queue
{
private:
	T* queue;
	int front;
	int rear;
	int capacity;

public:
	Queue(int queueCapacity = 10) : capacity (queueCapacity)
	{
		if (capacity < 1) throw "Queue capacity must be > 0";
		queue = new T[capacity];
		front = 0;
		rear = 0;
	}
	~Queue(){}

	bool IsEmpty()
	{
		return front == rear;
	}

	inline T& Front()
	{
		if (IsEmpty()) throw "Queue is empty. No front element";
		return queue[(front + 1) % capacity];
	}

	inline T& Rear()
	{
		if (IsEmpty()) throw "Queue is empty. No rear element";
		return queue[rear];
	}

	void Push(const T& x)
	{
		if ((rear + 1) % capacity == front)
		{
			ChangeSizeID(queue, capacity, 2 * capacity);
			capacity *= 2;
		}

		rear = (rear + 1) % capacity;
		queue[rear] = x;
	}

	void Pop()
	{
		if (IsEmpty()) throw "Queue is empty. Cannot delete.";
		front = (front + 1) % capacity;
		queue[front].~T();
	}

};

template <class T>
class Stack
{
private:
	int top;
	int capacity;
	T *stack;

public:

	Stack(int stackCapacity=10) : capacity (stackCapacity)
	{
		if (capacity < 1) throw "Stack capacity must be > 0";
		stack = new T[capacity];
		top = -1;
	}

	inline bool IsEmpty() const
	{
		return top == -1;
	}

	inline T& Top() const
	{
		if (IsEmpty()) throw "Stack is empty";
		return stack[top];
	}

	void Push(const T& item)
	{
		if (top == capacity - 1)
		{
			ChangeSizeID(stack, capacity, 2 * capacity);
			capacity *= 2;
		}
		stack[++top] = item;
	}

	void Pop()
	{
		if (IsEmpty()) throw "Stack is empty. Cannot delete.";
		stack[top--].~T();
	}
};

template <class T>
class TreeNode
{
	// freind class Tree<T>;
public:
	T data;
	TreeNode<T> *leftChild;
	TreeNode<T> *rightChild;

public:
	TreeNode()
	{
		leftChild = NULL;
		rightChild = NULL;
	}
	~TreeNode()
	{

	}
};

template <class T>
class Tree
{
private:
	TreeNode <T> *root; // �Ѹ� �κ��� ����Ű�� ������.

public:
	Tree()
	{
		TreeNode <char> *node[9];
		for (int i = 0; i < 9; i++)
		{
			node[i] = new TreeNode<char>; // ���� �Ҵ�
		}

		// å�� �ִ� BST�� �״�� ����
		node[0]->data = '+';
		node[1]->data = '*';
		node[2]->data = 'E';
		node[3]->data = '*';
		node[4]->data = 'D';
		node[5]->data = '/';
		node[6]->data = 'C';
		node[7]->data = 'A';
		node[8]->data = 'B';

		// ��� ����.
		root = node[0];
		root->leftChild = node[1];
		root->rightChild = node[2];
		node[1]->leftChild = node[3];
		node[1]->rightChild = node[4];
		node[3]->leftChild = node[5];
		node[3]->rightChild =node[6];
		node[5]->leftChild = node[7];
		node[5]->rightChild = node[8];
	}
	~Tree()
	{
		
	}

	void Inorder()
	{
		Inorder(root);
	}

	void Inorder(TreeNode <T> * currentNode)
	{
		if (currentNode)
		{
			Inorder(currentNode->leftChild);
			cout << currentNode->data << "  ";
			Inorder(currentNode->rightChild);
		}
	}

	void Preorder()
	{
		Preorder(root);
	}

	void Preorder(TreeNode <T> * currentNode)
	{
		if (currentNode)
		{
			cout << currentNode->data << "  ";
			Preorder(currentNode->leftChild);
			Preorder(currentNode->rightChild);
		}
	}

	void Postorder()
	{
		Postorder(root);
	}

	void Postorder(TreeNode <T> * currentNode)
	{
		if (currentNode)
		{
			Postorder(currentNode->leftChild);
			Postorder(currentNode->rightChild);
			cout << currentNode->data << "  ";
		}
	}

	void NonrecInorder()
	{
		Stack<TreeNode<T> *> s;
		TreeNode<T> *currentNode = root;

		while (1)
		{
			while (currentNode)
			{
				s.Push(currentNode);
				currentNode = currentNode->leftChild;
			}
			if (s.IsEmpty()) return;
			currentNode = s.Top();
			s.Pop();
			cout << currentNode->data << " ";
			currentNode = currentNode->rightChild;
		}
	}

	void Levelorder()
	{
		Queue<TreeNode<T> *> q;
		TreeNode<T> *currentNode = root;
		while (currentNode)
		{
			cout << currentNode->data << " ";
			if (currentNode->leftChild) q.Push(currentNode->leftChild);
			if (currentNode->rightChild) q.Push(currentNode->rightChild);
			if (q.IsEmpty()) return;
			currentNode = q.Front();
			q.Pop();
		}
	}
};

template <class T>
class InorderIterator
{
private:
	Stack <TreeNode<T> *> s;
	TreeNode<T> *currentNode;
public:
	InorderIterator() { currentNode = root; }
	T* Next()
	{
		while (currentNode)
		{
			s.Push(currentNode);
			currentNode = currentNode->leftChild;
		}
		if (s.IsEmpty()) return;
		currentNode = s.Top();
		s.Pop();
		T& Temp = currentNode->data;
		currentNode = currentNode->rightChild;
		return &temp;
	}
};