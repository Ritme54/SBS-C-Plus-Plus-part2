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
		int data;

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
	}



	void insert(T data)
	{

		if (root == nullptr)
		{
			root = createNode(data);
		}
		else
		{
			Node* currentNode = root;

			while (currentNode != nullptr)
				if (currentNode->data > data)
				{
					return;
				}
				else if (currentNode->data == data)
				{
					if (currentNode->left == nullptr)
					{
						currentNode->left = createNode(data);
						return;
					}
					else
					{
						currentNode = currentNode->left;
					}

				}
				else
				{
					if (currentNode->right == nullptr)
					{
						currentNode->right = createNode(data);
						return;
					}
					else
					{
						currentNode = currentNode->right;
					}
				}
		}
	}
	void release(Node* root) 
	{
		if (root != nullptr)
		{
			release(root->left);
			release(root->right);

			delete root;
		}

	}


};

int main()
{
	Set<int> tree;

	tree.insert(10);
	







}