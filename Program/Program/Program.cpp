#include <iostream>

using namespace std;


template<typename T>
class Vector
{
public:
	Vector()
	{
		size = 0;
		capacity = 0;
		container = nullptr;
		cout << "초기화" << endl;
	};
	~Vector()
	{
		if (container != nullptr)
		{
			delete[]container;
		}
	}


	void resize(int newSize)
	{
		//1.capacity에 새로운 size값을 저장한다.
		capacity = newSize;

		//2.새로운 포인터 변수를 생성해서 새롭게 만들어진 메모리 공간을 가리키도록 한다.
		T*pointer = new T[capacity]
		//3.새로운 메모리 공간의 값을 초기화(쓰래기값제거)
			for (int i = 0; i < capacity; i++)
			{
				pointer[i] = NULL;
			}
		//4.기존 배열에 있는 값을 복사해서 새로운 배열에 넣어준다.
			for (int i = 0; i < size; i++)
			{
				pointer[i] = container[i];
			}
		//5.기존 배열의 메모리를 해제한다.(Nullptr이 아닐때 해제한다!)
			if (container !=nullptr)
			{
				delete[] container
			}
		//6.기존 베열을 가리키던 포인터 변수의 값을 새로운 배열의 시작 주소로 가리킨다.
			container = pointer;
			capacity = newcapacity;
		
	}

	void push_back(T data)
	{
		//데이터가 존재하지 않을때= 하나를 우선 만든다.(size=0)
		//값을 하나 더 넣는다-> 사이즈와 값 크기가  증가한다.
		if (size== capacity)
		{
			int newcapacity = (capacity == 0) ? 1 : capacity * 2;
			resize(newcapacity);
		}
		container[size] = value;
		size++

	}

	void display() const {
		std::cout << "Vector 내용: [";
		for (size_t i = 0; i < size; ++i) {
			std::cout << container[i] << (i == size - 1 ? "" : ", ");
		}
		std::cout << "], 크기: " << size << ", 용량: " << capacity << std::endl;
	}

private:
	int size; //사이즈
	int capacity;//크기
	T* container;//컨테이너



};


int main()
{
	Vector<int>list;

	list.push_back(10);
	list.display();
		

	return 0;
}