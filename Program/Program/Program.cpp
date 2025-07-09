#include <iostream>

using namespace std;

#pragma region 양방향
//previous Node, nextNode
//size, head, tail(마지막 노드)
#pragma endregion


template<typename T>
class List
{
private:
	struct Node
	{
		T data;
		Node* previousNode;
		Node nextNode;

	};
	int size;
	Node* head;
	Node* tail;
	
public:
	List();
	{
		size = 0;
		head = NULL;
		tail = NULL;

	}






	~List();
	{
	
	}


};

List::List()
{
}

List::~List()
{
}

int main()
{





}