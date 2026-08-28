#include <iostream>
#include <cstdlib>
#include <ctime>

// min과 max 사이의 랜덤 정수를 반환하는 함수.
int RandomRange(int min, int max)
{
	// min-max 사이의 거리.
	int diff = (max - min) + 1;
	return ((diff * rand()) / (RAND_MAX + 1)) + min;
}

void PrintArray(const int* array, int length)
{
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix];

		if (ix < length - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "\n";
}

// 피벗 선택 함수.
int Partition(int* array, int left, int right)
{
	// 피벗을 선택하는 방법은 다양한데 간단하게 첫번째 요소를 선택.
	int pivot = array[left];

	// 왼쪽에서 오른쪽으로 이동하면서 피벗보다 큰 값 찾는데 사용.
	int low = left + 1;
	
	// 오른쪽에서 왼쪽으로 이동하면서 피벗보다 작은 값 찾는데 사용.
	int high = right;

	// low와 high 인덱스가 교차할 때까지 진행.
	while (low <= high)
	{
		// 왼쪽에서 오른쪽으로 이동하면서 값 찾기.
		while (low <= right && array[low] <= pivot)
		{
			++low;
		}

		// 오른쪽에서 왼쪽으로 이동하면서 값 찾기.
		while (high > left && pivot <= array[high])
		{
			--high;
		}

		// 두 인덱스가 교차했으면 루프 종료.
		if (low > high)
		{
			break;
		}

		// low의 값과 high의 값을 서로 교환.
		std::swap<int>(array[low], array[high]);
	}

	// 피벗을 최종 위치로 이동 처리.
	// array[left] 값이 피벗 값(첫 번째 요소).
	std::swap<int>(array[left], array[high]);

	// 피벗 위치 반환(배열의 인덱스).
	// high를 반환하는 이유는 앞에서 초기 피벗 선택 위치와 
	// high의 위치를 교환했기 때문.
	return high;
}

// 퀵정렬 함수(재귀).
void QuickSort(int* array, int left, int right)
{
	// 종료 조건.
	if (left >= right)
	{
		return;
	}

	// 분할 - 피벗 선택 및 분할.
	int pivotIndex = Partition(array, left, right);

	// 왼쪽 분할 배열 정렬 진행.
	QuickSort(array, left, pivotIndex - 1);

	// 오른쪽 분할 배열 정렬 진행.
	QuickSort(array, pivotIndex + 1, right);
}

int main()
{
	// 랜덤에 시드 전달.
	srand(static_cast<uint32_t>(time(nullptr)));

	// 배열 수.
	const int length = 1000;

	// 배열.
	int original[length] = {};
	for (int ix = 0; ix < length; ++ix)
	{
		int value = RandomRange(1, length);
		original[ix] = value;
	}

	// 정렬에 사용할 배열.
	int array[length] = {};

	// 메모리 복사 -> 빠름.
	memcpy(array, original, sizeof(int) * length);

	// 출력.
	std::cout << "정렬 전 배열: ";
	PrintArray(array, length);

	// 정렬.
	QuickSort(array, 0, length - 1);

	// 정렬 후 출력.
	std::cout << "\n정렬 후 배열: ";
	PrintArray(array, length);
}