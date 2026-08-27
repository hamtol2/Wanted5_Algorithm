#include <iostream>

// 로직 주입을 위한 함수 포인터 타입 선언.
using Comparer = bool (*)(int, int);

// 비교 함수.
bool Less(int a, int b) { return a < b; }
//bool Greater(int a, int b) { return a > b; }

// 함수 객체 (Functor).
template<typename T>
struct Greater
{
	// 호출 연산자 오버로딩.
	bool operator()(const T& a, const T& b) { return a > b; }
};

// 교환 함수.
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 선택 정렬 함수.
void SelectionSort(int* array, const int length, 
	Comparer comparer = Less)
{
	// 예외 처리.
	if (length <= 1)
	{
		return;
	}

	for (int ix = 0; ix < length - 1; ++ix)
	{
		// 선택한 수의 위치(인덱스)를 저장할 변수.
		int valueIndex = ix;

		// 현재 위치(ix)에서 끝까지 반복.
		for (int jx = ix + 1; jx < length; ++jx)
		{
			// 비교 (로직 활용).
			if (comparer(array[valueIndex], array[jx]))
			{
				valueIndex = jx;
			}
		}

		// 앞에서 선택한 값이 현재 위치와 다르면 교환.
		if (valueIndex != ix)
		{
			Swap(array[ix], array[valueIndex]);
		}
	}
}

// 배열 출력 함수.
void PrintArray(int* array, const int length)
{
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix];

		// 마지막이 아니면 콤마 출력.
		if (ix < length - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "\n";
}

int main()
{
	// 자료 집합.
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// 데이터 수.
	const int length = _countof(array);

	std::cout << "정렬 전 출력: ";
	PrintArray(array, length);

	//SelectionSort(array, length);
	//std::greater<int> greater;
	SelectionSort(
		array, 
		length, 
		[](int a, int b) { return a > b; }
	);

	std::cout << "정렬 후 출력: ";
	PrintArray(array, length);
}