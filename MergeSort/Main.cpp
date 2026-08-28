#include <iostream>
#include <cstdlib>
#include <ctime>

// 병합 정렬 함수(재귀).
void MergeSort(int* array, int length)
{
	// 종료 조건 (더이상 분할할 수 없으면 종료).
	if (length <= 1)
	{
		return;
	}

	// 반으로 나누면서 분할 진행.
	// 중간 인덱스.
	int middle = length / 2;

	// 왼쪽으로 나눌 배열의 크기.
	int leftArrayLength = middle;

	// 오른쪽으로 나눌 배열의 크기(전체 크기에서 왼쪽 배열 크기를 뺌).
	int rightArrayLength = length - middle;

	// 분할된 배열 선언(동적 할당).
	int* leftArray = new int[leftArrayLength] {};
	int* rightArray = new int[rightArrayLength] {};

	// 분할된 왼쪽 배열에 값 복사.
	//for (int ix = 0; ix < leftArrayLength; ++ix)
	//{
	//	leftArray[ix] = array[ix];
	//}

	memcpy(leftArray, array, sizeof(int) * leftArrayLength);

	// 분할된 오른쪽 배열에 값 복사.
	memcpy(rightArray, array + middle, sizeof(int) * rightArrayLength);

	// 분할을 이어서 진행 (재귀).
	MergeSort(leftArray, leftArrayLength);
	MergeSort(rightArray, rightArrayLength);

	// 분할이 재귀적으로 모두 끝나면 병합을 진행.
	// ... 

	// 사용한 배열 해제.
	delete[] leftArray;
	leftArray = nullptr;

	delete[] rightArray;
	rightArray = nullptr;
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

int main()
{
	// 배열.
	const int length = 1000;

	// 정렬할 배열 선언 - 값 유지에 사용.
	int* original = new int[length] {};

	// 랜덤을 활용해서 배열에 값 저장.
	for (int ix = 0; ix < length; ++ix)
	{
		original[ix] = RandomRange(1, length);
		//*(original + ix) = RandomRange(1, length);
	}

	// 정렬에 사용할 배열.
	int* array = new int[length] {};

	// 메모리 통복사.
	memcpy(array, original, sizeof(int) * length);

	// 정렬.

	delete[] original;
	original = nullptr;

	delete[] array;
	array = nullptr;
}