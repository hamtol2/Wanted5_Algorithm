#include <iostream>

// 배열의 원소 개수를 구하는 매크로.
#define ArraySize(array) ( sizeof(array) / sizeof(array[0]) )

// 현재 노드를 기준(루트)으로 서브 트리를 최대(또는 최소)힙으로 만드는 함수.
void Heapify(int* array, int length, int index)
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
		if (leftChild < length && array[leftChild] > array[selected])
		{
			selected = leftChild;
		}

		// 오른쪽 자손이 현재 노드 보다 크면(또는 작음) 인덱스 교환.
		if (rightChild < length && array[rightChild] > array[selected])
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

int main()
{
	// 배열.
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6,	9, 10, 15, 13, 14, 12, 17, 16 };

	// 배열 원소 개수.
	const int length = ArraySize(array);

	// 데모 - 최대힙 구성.
	// 자손을 가진 마지막 부모 인덱스.
	const int lastParentIndex = length / 2 - 1;
	for (int ix = lastParentIndex; ix >= 0; --ix)
	{
		Heapify(array, length, ix);
	}

	std::cin.get();
}