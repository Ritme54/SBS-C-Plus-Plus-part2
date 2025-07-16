#include <iostream>

using namespace std;


template<typename T>
class CircleList
{
public:
	CircleList()
	{
		size = 0;

		head = nullptr;
		cout << "초기화" << endl;
		
	}

	void push_back(T data)
	{

		Node* newNode = new Node;
		newNode->data = data;
		

		if (head == nullptr)
		{
			head = newNode; //리스트가 비여있을때.
			newNode->next = newNode;

		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
			head = newNode;
		}
		size++;
	}

	void push_front(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		if (head == nullptr)
		{
			newNode->next = newNode;
			head = newNode; //리스트가 비여있을때.
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
		}
		size++;
	}

	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "List is empty" << endl;
			return;
		}
		Node* delNode = head->next;

		
		if(head->next==head)
		{
			head = nullptr;
		}
		else
		{
			head->next = delNode->next;
		}
		delete delNode;
		size--;
	}


	void printList() {
		if (head == nullptr) {
			std::cout << "리스트가 비어 있습니다." << std::endl;
			return;
		}
		Node* current = head->next; // 첫 번째 노드부터 시작
		do {
			std::cout << current->data << " ";
			current = current->next;
		} while (current != head->next);
		std::cout << std::endl;
	}


	bool empty()
	{
		return (head == nullptr);
	}

	~CircleList()
	{
	
		cout << "삭제" << endl;


	}

private:
	struct Node
	{
		T data;
		Node* next;
	};

Node* head;
int size;

};


int main()
{
	CircleList<int> list;
	list.push_back(10);
	list.push_back(20);
	list.push_back(30);
	list.push_front(5);
	list.push_front(1);
	list.pop_front();

	cout << list.empty() << endl;

	list.printList();



	return 0;
}