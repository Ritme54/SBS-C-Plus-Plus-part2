#include <iostream>

using namespace std;


template<typename T>
class List
{
private:

	int size;

	struct Node
	{
		T data;
		Node* next;
	};

	Node* head;

public:
	List();

	void push_front(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = nullptr;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		size++;
	};

	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "List is empty" << endl;

		}
		else
		{
			Node* delnode = head;
			head = delnode->next;
			delete delnode;
		}
		size--;
	};

	void push_back(T data)
	{
		//newNode
		//head
		//currentNode
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode; //리스트가 비여있을때.

		}
		else
		{

			Node* currentNode = head;
			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;//마지막 노드까지 이동

			}
			currentNode->next = newNode;
		}
		size++
	};

	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "List is empty" << endl;
			return;
		}
		else if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* currnetNode = head;
			Node* previousNode = nullptr;

			while (currnetNode->next != nullptr)
			{
				previousNode = currnetNode;
				currnetNode= currnetNode->next; //마지막 노드까지 이동
			}
			delete currnetNode; //마지막 노드 삭제
			previousNode->next = nullptr; //마지막 노드의 next를 nullptr로 설정
			size--;
		}
	}



	~List();

	//리스트의 크기를 나타내는 변수
	//리스트의 시작 위치를 가리키는 포인터

};



int main()
{
#pragma region AAAAAAAAAAAAA
	//선형 컨테이너
	//연결 리스트
	//{-단일 연결 리스트
		//-양방향 연결 리스트
		//원형연결 리스트}


	//자기 자신을 가리키는 포인터 
	//Node
	//리스트의 크기를 나타내는 변수

#pragma endregion
	//사이즈가 0이거나 포인터가 nullptr일때 컨테이너가 비여 있다.


	List<int> list;
	//리스트의 크기를 나타내는 변수
	//리스트의 시작 위치를 나타내는 포인터
	list.push_front(10);
	list.push_front(20);
	list.push_back(25);
	list.pop_back();

};

template<typename T>
inline List<T>::List()
{
	size = 0;

	head = nullptr;
	cout << "초기화" << endl;
}

template<typename T>
List<T>::~List()
{
	while (head != nullptr)//헤드가 nullptr을 가리킬 때까지 계속 반복
	{
		Node* delnode = head;
		head = delnode->next;
		delete delnode;
		size--;
		//pop_front(); :위 함수를 통째로 가저오는 방법
	}
	cout << "삭제" << endl;
}
