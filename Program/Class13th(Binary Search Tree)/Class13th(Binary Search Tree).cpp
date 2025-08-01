#include <iostream>



using namespace std;




template <typename T>
class Set
{
private:

	struct Node
	{
		Node* left;
		Node* right;
		T data;

	};
	int size;
	Node* root;
	Node* currentNode;

	Node* createNode(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->left = nullptr;
		newNode->right = nullptr;
		size++;

		return newNode;

	}


public:
	Set()
	{
		size = 0;
		root = nullptr;
	}
	~Set()
	{


		release(root);
		this->root = nullptr;
		size = 0;

	}



	void insert(T data)
	{

		if (root == nullptr)
		{
			root = createNode(data);
			size++;
			cout << "값 : " << data << endl;
			return;
		}
		Node* currentNode = root;
		Node* parentNode = nullptr;

		while (currentNode != nullptr)
		{
			parentNode = currentNode;

			if (data < currentNode->data)
			{
				currentNode = currentNode->left;

			}
			else if (data > currentNode->data)

			{
				currentNode = currentNode->right;
			}
			else
			{
				return;
			}
		}
		if (data < parentNode->data)
		{
			parentNode->left = createNode(data);

		}
		else
		{
			parentNode->right = createNode(data);
		}
		size++;
		cout << "값 : " << data << endl;
		return;

	}

	void erase(T data)
	{


		if (root == nullptr)
		{
			cout << "set is empty" << endl;
		}
		else
		{
			Node* currentNode = root;
			Node* parentNode = nullptr;

			while (currentNode != nullptr && currentNode->data != data)
			{
				if (data < currentNode->data)
				{
					parentNode = currentNode;
					currentNode = currentNode->left;
				}
				else if (data > currentNode->data)
				{
					parentNode = currentNode;
					currentNode = currentNode->right;

				}

			}
			if (currentNode == nullptr)
			{
				cout << "no data" << "";

			}
			else if (currentNode->left == nullptr && currentNode->right == nullptr)
			{
				if (parentNode != nullptr)
				{
					if (parentNode->left == currentNode)
					{
						parentNode->left = nullptr;
					}
					else if (parentNode->right == currentNode)
					{
						parentNode->right = nullptr;
					}

					delete currentNode;
					size--;
					return;
				}
			}
			else if ((currentNode->left == nullptr || currentNode->right == nullptr))
			{
				Node* childNode = (currentNode->left != nullptr) ? currentNode->left : currentNode->right;
				if (parentNode == nullptr)
				{
					root = childNode;
				}
				else
				{
					if (parentNode->left == currentNode)
					{
						parentNode->left = childNode;
					}
					else
					{
						parentNode->right = childNode;
					}
					delete currentNode;
					cout << "삭제" << data << endl;
					size--;
					return;

				}

			}
			else
			{
				if (currentNode == nullptr)
				{
					cout << "  " << endl;
				}
				if (currentNode->left != nullptr && currentNode->right != nullptr)
				{
					Node* traceNode = currentNode;
					Node* childNode = currentNode->right;
					while (childNode->left != nullptr)
					{
						traceNode = childNode;
						childNode = childNode->left;

					}
					currentNode->data = childNode->data;

					if (traceNode->left == childNode)
					{
						traceNode->left = childNode->right;

					}
					else
					{
						traceNode->right = childNode->right;

					}
					delete childNode;
					size--;
					cout << "삭제" << data << endl;
					return;

				}


			}
		}
	}
	void release(Node* rootnode)
	{
		if (rootnode != nullptr)
		{
			release(rootnode->left);
			release(rootnode->right);

			delete rootnode;
		}

	}
	void inorder()
	{
		inorder(root);
	}

	void inorder(Node* root)
	{
		if (root == nullptr)
		{
			root = this->root;
		}
		if (root != nullptr)
		{
			inorder(root->left);

			cout << root->data << " ";
			inorder(root->right)
		}
	}

};


int main()
{
	Set<int> tree;

	tree.insert(10);
	tree.insert(15);
	tree.insert(7);
	tree.insert(33);

	tree.insert(5);
	tree.insert(13);
	tree.erase(7);
	tree.erase(15);

	return 0;



}