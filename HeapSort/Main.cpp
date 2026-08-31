#include <iostream>
#include <functional>
#include <Windows.h>
#include <algorithm>

// 배열의 원소 개수를 구하는 매크로.
#define ArraySize(array) ( sizeof(array) / sizeof(array[0]) )

// 현재 노드를 기준(루트)으로 서브 트리를 최대(또는 최소)힙으로 만드는 함수.
void Heapify(
	int* array,
	int length,
	int index,
	std::function<bool(int, int)> comparer)
{
	while (true)
	{
		// 가장 큰(또는 작은) 값을 가진 인덱스.
		int selected = index;

		// 왼쪽 자손 인덱스.
		int leftChild = index * 2 + 1;

		// 오른쪾 자손 인덱스.
		int rightChild = index * 2 + 2;

		// 왼쪽 자손이 현재 노드 보다 크면(또는 작으면) 인덱스 교환.
		//if (leftChild < length && array[leftChild] > array[selected])
		if (leftChild < length
			&& comparer(array[leftChild], array[selected]))
		{
			selected = leftChild;
		}

		// 오른쪽 자손이 현재 노드 보다 크면(또는 작음) 인덱스 교환.
		//if (rightChild < length && array[rightChild] > array[selected])
		if (rightChild < length
			&& comparer(array[rightChild], array[selected]))
		{
			selected = rightChild;
		}

		// 현재 노드가 컸다면, 힙이 유지됐기 때문에 종료.
		if (selected == index)
		{
			break;
		}

		// 값 교환.
		std::swap(array[index], array[selected]);

		// 값을 교환한 위치에서 다시 자손 노드들과 비교.
		index = selected;
	}
}

// 힙정렬 함수.
void HeapSort(
	int* array,
	int length,
	std::function<bool(int, int)> comparer = std::greater())
{
	// 힙 구성.
	const int lastParentIndex = length / 2 - 1;
	for (int ix = lastParentIndex; ix >= 0; --ix)
	{
		Heapify(array, length, ix, comparer);
	}

	// 루트의 최대(또는 최소) 값을 배열의 뒤쪽부터 정렬.
	for (int ix = length - 1; ix > 0; --ix)
	{
		// 루트(0번 인덱스)와 정렬되지 않는 범위의 마지막 요소 교환.
		std::swap(array[0], array[ix]);

		// 교환을 한 뒤로는 다시 힙으로 만들어야 함.
		Heapify(array, ix, 0, comparer);
	}
}

// 랜덤에 시드 값 적용하는 함수.
void SRand()
{
	srand(static_cast<uint32_t>(time(nullptr)));
}

// min에서 max 사이의 정수를 반환하는 랜덤 함수.
int RandomRange(int min, int max)
{
	// 범위 구하기.
	int diff = (max - min) + 1;
	return ((diff * rand()) / (RAND_MAX + 1)) + min;
}

// 현재 시간 가져오기.
int64_t GetTime()
{
	LARGE_INTEGER counter;
	QueryPerformanceCounter(&counter);
	return counter.QuadPart;
}

// 경과 시간 계산 함수.
float GetElapsed(int64_t start, int64_t end)
{
	// 밀리세컨드 -> 1/1000초. 1밀리세컨드 -> 0.001초.
	// 예: 1/60초 -> 0.016초... 16밀리시컨드 -> 16/1000 -> 0.016초.

	// 해상도(주파수).
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);
	return static_cast<float>(end - start) / frequency.QuadPart;
}

int main()
{
	// 배열.
	//int array[] = { 5, 2, 8, 4, 1, 7, 3, 6,	9, 10, 15, 13, 14, 12, 17, 16 };

	// 배열 원소 개수.
	//const int length = ArraySize(array);
	const int length = 10000000;
	int* array = new int[length] {};

	// 배열 값 설정.
	SRand();
	for (int ix = 0; ix < length; ++ix)
	{
		array[ix] = RandomRange(1, 60000);
	}

	auto start = GetTime();

	// 힙 정렬.
	//HeapSort(array, length, std::less());
	HeapSort(array, length, [](int a, int b) { return a > b; });

	float elapsed = GetElapsed(start, GetTime());

	std::cout << "Elapsed: " << elapsed << "\n";

	delete[] array;
	array = nullptr;

	std::cin.get();
}