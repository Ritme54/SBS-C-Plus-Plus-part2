//#include <iostream>
//
//using namespace std;
//
//#pragma region 양방향
////previous Node, nextNode
////size, head, tail(마지막 노드)
//#pragma endregion
//
//
//template<typename T>
//class N2
//{
//private:
//	struct Node
//	{
//		T data;
//		Node* next;
//	};
//
//	Node* last;
//	int current_size;
//
//
//public:
//	N2();
//	{
//
//
//		void Remove(T data)
//		{
//			Node* current = head;
//			while (current != nullptr)
//			{
//				if (current = ->data == data)
//				{
//					Node* prevNode = current->prev;
//					Node* nextNode = current->next;
//
//					if (prevNode != nullptr)
//					{
//						prevNode->next = nextNode;
//					else
//					{
//						head = nextNode;
//					}
//					if (nextNode != nullptr)
//					{
//						nextNode->prev = prevNode;
//					}
//					else
//					{
//						tail = prevNode;
//					}
//
//					}
//					delete current;
//					//return;
//
//				}
//				current = current->next;
//
//			}
//		}
//
//		if (deleteNode == head)
//		{
//			pop_front();
//		}
//		else if (deleteNode == tail)
//		{
//			pop_back();
//		}
//		else
//		{
//			deleteNode->previous->next = deleteNode->next;
//			deleteNode->next->previous = deleteNode->previous;
//
//			nextNode = deleteNode->next;
//
//			delete deleteNode;
//
//			deleteNode = nextNode;
//
//			size--;
//		}
//
//
//
//
//	}
//
//	~N2();
//	{
//		if (last == nullptr)
//		{
//			return;
//		}
//		Node* head = last->next;
//		Node* current = head;
//		do
//		{
//			Node* next_node = current->next;
//			delete current;
//			current = next_node;
//		} while (current != head);
//	}
//
//
//
//}
//
//
//};
//
//int main()
//{
//
//
//
//
//
//}