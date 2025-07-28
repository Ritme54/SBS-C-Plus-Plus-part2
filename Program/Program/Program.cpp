#include <iostream>
#include <vector>
#include <ostream>
#include <memory>

using namespace std;


template<typename T>
class AdjacencyMatrix
{
private:
	int size; //정점의 개수
	int capacity; //최대 용량
	T* vertex;//정점의 집합

	int** matrix;
	int edgeCount; // matrixcount




public:
	AdjacencyMatrix()
	{
		size = 0;
		capacity = 0;
		vertex = nullptr;
		matrix = nullptr;
		edgeCount = 0; //인접 행렬의 개수
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (size >= capacity)
		{
			resize(capacity * 2);
		}
		vertex[size++] = data;
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
		for (int i = 0; i < size; i++)
		{
			pointer[i] = vertex[i];
		}
		//5.기존 배열의 메모리를 해제한다.(Nullptr이 아닐때 해제한다!)
		if (vertex != nullptr)
		{
			delete[] vertex;
		}
		//6.기존 베열을 가리키던 포인터 변수의 값을 새로운 배열의 시작 주소로 가리킨다.
		vertex = pointer;
		capacity = newSize;

	}


	void resize()
	{
		//기존에 있던 matrix의 데이터를 옮겨준다
		int** newMatrix = new int* [size];
		for (int i = 0; i < size; i++)
		{
			newMatrix[i] = new int[size] {0};
		}
		//기존의 matrix의 크기를 oldSize로 설정한다.
		for (int i = 0; i < edgeCount; i++)
		{
			for (int j = 0; j < edgeCount; j++)
			{
				newMatrix[i][j] = matrix[i][j];
			}
		}

		//기존의 matrix의 메모리를 해제한다.

		if (matrix!=nullptr)
		{
			for (int i = 0; i < edgeCount; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
		}
		//matrix 포인터가 새로 만들어진 행렬을 가리키게 한 다음 행렬의 크기도 다시 설정한다.
		matrix = newMatrix;
		edgeCount = size * size;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = 0;

			}
		}
		cout << "완" << endl;

	}

	void edge(int i, int j)
	{
		//1. vertex가 없는 상태에서 연결하면 인접 행렬이 없다고 나와야 한다.
		if (vertex == nullptr || size == 0)
		{
			cout << "행렬 없음" << endl;
			return;
		}
		//2. vertex의 크기 범위를 벗어나게 되면 연결이 되지 않도록 설정해야 한다.

		if (i < 0 || i >= size || j < 0 || j >= size)
		{
			cout << "범위를 벗어났습니다." << endl;
			return;
		}
		//3. 인접 행렬이 없을 때 정점의 크기만큼 인접 행렬을 생성합니다.
		if (matrix == nullptr || edgeCount == 0)
		{
			matrix = new int* [size];
			for (int k = 0; k < size; k++)
			{
				matrix[k] = new int[size];
				for (int l = 0; l < size; l++)
				{
					matrix[k][l] = 0; //초기화
				}
			}
			edgeCount = size * size;
		}
						
	}
	~AdjacencyMatrix()
	{


	};


};



int main()
{
	//Vertex=정점
	//Edge 간선
	// 
	//무방향 그래프 : 정점 간의 연결이 양방향으로 연결되어 있는 그래프
	//방향 그래프 : 정점 간의 연결이 한 방향으로만 연결되어 있는 그래프

	//방향 그래프-차수-진출 차수
	//방향 그래프-차수-진입 차수
	//0은 연결되어 있지 않다. 1이 연결되어있다.

	//그래프의 표현 방법
	//1.인접 행렬
	// 2차원 배열로 표현
	// 예시) Vertex가 3개일때 3*3으로 표현하고, 첫 칸은 0.0으로 시작한다.
	// 무방향 그래프는 대칭 행렬로 표현된다.
	// 방향 그래프는 대칭 행렬로 표현되지 않는다.
	// 
	// 
	// 2. 인접 리스트
	// 포인터 베열 방식
	// // 예시) Vertex가 3개일때 3개의 포인터를 가진 배열을 만들고, 각 포인터는 연결된 정점의 주소를 가리킨다.
	// 값이 들어올때 push_front으로 연결된 정점의 주소를 넣는다.(void push_front())
	// class AdjacencyMatrix
	// {
	//		정점의 개수 <-
	//		인접 행렬의 개수
	//		최대 용량 <-
	//		정점의 집합 <-
	//		인접 행렬	 
	// }
	// void push(T data)
	// void resize(int newSize)
	// 이중 포인터로 int **ptr = new int*[5] //(포인터 배열로 동적 할당)
	// 인접 행렬의 메모리 - 1차원 배열(모든 데이터가 들어갈 수 있는 배열)
	//
	// void edge(int i, int j)
	//1. vertex가 없는 상태에서 연결하면 인접 행렬이 없다고 나와야 한다.
	//2. vertex의 크기 범위를 벗어나게 되면 연결이 되지 않도록 설정해야 한다.
	//인접 행렬을 int **(더블포인트)로 지정 (bool도 가능)
	// matrix= new int*[size];
	// matrix= new int*[행의 크기];
	//resize(int)
	// resize()
	// 3. 인접 행렬이 없을 때 정점의 크기만큼 인접 행렬을 생성합니다.
	// 
	// 
	//4. 인접 행렬의 크기를 정점의 크기만큼 늘려준다.

	//void resize()
	//기존에 있던 matrix의 데이터를 옮겨준다.
	//기존의 matrix의 메모리를 해제한다.
	//matrix 포인터가 새로 만들어진 행렬을 가리키게 한 다음 행렬의 크기도 다시 설정한다.
	//ostream & operator<<(ostream& os, const AdjacencyMatrix<T>& matrix)

	AdjacencyMatrix<int> adjacencyMatrix;
	adjacencyMatrix.push(1);
	adjacencyMatrix.push(2);
	adjacencyMatrix.push(5);
	adjacencyMatrix.edge(0, 2);
	//값 출력(표시)
	



	return 0;
}