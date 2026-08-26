#include <iostream>
#include <vector>
#include <algorithm>

// 재귀를 활용한 이진 탐색.
int BinarySearchRecursive(const int* array, const int target, int start, int end)
{
	// 종료 조건.
	// 시작 인덱스가 종료 인덱스보다 커지면 검색 실패.
	if (start > end)
	{
		return -1;
	}

	// 중간 인덱스.
	int middle = (start + end) / 2;

	// 찾았는지 확인.
	if (array[middle] == target)
	{
		return middle;
	}

	// 배열의 값이 검색하려는 값보다 큰 경우.
	if (array[middle] > target)
	{
		return BinarySearchRecursive(array, target, start, middle - 1);
	}

	// 중간 값보다 크면 오른쪽 범위를 탐색.
	return BinarySearchRecursive(array, target, middle + 1, end);
}

// 반복적인(반복문) 방법으로 이진 탐색을 처리하는 함수.
int BinarySearchIterative(const int* array, const int length, const int target)
{
	// 이진 탐색에 사용할 구간(범위).
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		// 중간 인덱스.
		int middle = (start + end) / 2;

		// 찾았는지 검사.
		if (array[middle] == target)
		{
			return middle;
		}

		// 중간값보다 작으면 왼쪽 검색.
		if (array[middle] > target)
		{
			end = middle - 1;
		}

		// 중간값보다 크면 오른쪽 검색.
		else
		{
			start = middle + 1;
		}
	}

	// 탐색 실패.
	return -1;
}

int main()
{
	// 배열.
	const int array[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	const int length = sizeof(array) / sizeof(array[0]);
	const int target = 10;

	// 인덱스 검색.
	//int result = BinarySearchRecursive(array, target, 0, length - 1);
	int result = BinarySearchIterative(array, length, target);

	// 검색 성공.
	if (result != -1)
	{
		std::cout << "검색 성공. 인덱스: " << result << "\n";
	}
	else
	{
		std::cout << "검색 실패.\n";
	}

	//std::vector<int > testVector;
	//bsearch()
}