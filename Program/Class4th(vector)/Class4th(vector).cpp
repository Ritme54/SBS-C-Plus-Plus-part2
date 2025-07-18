#include <iostream>

using namespace std;


template<typename T>
class Vector
{
public:
	Vector()
	{
		count = 0;
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
		T* pointer = new T[capacity];
		//3.새로운 메모리 공간의 값을 초기화(쓰래기값제거)
		for (int i = 0; i < capacity; i++)
		{
			pointer[i] = NULL;
		}
		//4.기존 배열에 있는 값을 복사해서 새로운 배열에 넣어준다.
		for (int i = 0; i < count; i++)
		{
			pointer[i] = container[i];
		}
		//5.기존 배열의 메모리를 해제한다.(Nullptr이 아닐때 해제한다!)
		if (container != nullptr)
		{
			delete[] container;
		}
		//6.기존 베열을 가리키던 포인터 변수의 값을 새로운 배열의 시작 주소로 가리킨다.
		container = pointer;
		capacity = newSize;

	}

	void push_back(T data)
	{
		if (count == capacity)
		{
			int newSize = (capacity == 0) ? 1 : capacity * 2;
			resize(newSize);
		}
		container[count] = data;
		count++;

	}

	void display() const {
		std::cout << "Vector 내용: [";
		for (size_t i = 0; i < count; ++i) {
			std::cout << container[i] << (i == count - 1 ? "" : ", ");
		}
		std::cout << "], 크기: " << count << ", 용량: " << capacity << std::endl;
	}

	T& operator[](size_t index)
	{
		if (index >= count)
		{
			cout << "Index out of bounds" << endl;
		}
		return container[index];

	}
	const int& size()
	{
		return count;
	}

	void pop_back()
	{
		if (count <= 0)
		{
			cout << "vector is empty" << endl;

		}
		else
		{
			container[--count] = NULL;
		}
		return;
	}

	//null로 초기화





private:
	int count; //사이즈
	int capacity;//크기
	T* container;//컨테이너
};


int main()
{
	Vector<int>vector;

	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);
	vector.push_back(40);
	vector.push_back(50);
	vector.pop_back();
	vector.display();
	cout << vector[0] << endl;

	for (int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << endl;
	}

	return 0;
}