#include <iostream>

using namespace std;

int main()
{
#pragma region 거품 정렬

	//거품 정렬이란
	//인접한 두 원소를 비교하여 정렬하는 알고리즘이다.
	//시간 복잡도는 O(n^2)이다.
	//거품 정렬의 동작 방식
	//1. 첫 번째 원소와 두 번째 원소를 비교한다.
	//2. 첫 번째 원소가 두 번째 원소보다 크면 두 원소를 교환한다.
	//3. 두 번째 원소와 세 번째 원소를 비교한다.
	//4. 두 번째 원소가 세 번째 원소보다 크면 두 원소를 교환한다.
	//5. 마지막 원소까지 반복한다.
	//6. 마지막 원소를 제외한 나머지 원소에 대해 1~5번을 반복한다.
	int arr[] = { 5, 3, 8, 4, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				//swap
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}


#pragma endregion

	


	return 0;
}