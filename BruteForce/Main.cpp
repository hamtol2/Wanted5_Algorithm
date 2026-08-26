#include <iostream>
#include <cstring>

//int StringLength(const char* string)
//{
//	int count = 0;
//	while (string[count] != '\0')
//	{
//		++count;
//	}
//
//	return count;
//}

// 문자열에서 특정 패턴 검색하는 함수.
// 예: ronnie에서 nie 패턴 찾기.
int FindPatternIndex(const char* text, const char* pattern)
{
	// 두 문자열의 길이.
	const int textLength = static_cast<int>(strlen(text));
	const int patternLength = static_cast<int>(strlen(pattern));

	// 문자열에서 패턴 찾기.
	for (int ix = 0; ix <= textLength - patternLength; ++ix)
	{
		// 검색됐을 때 반환할 패턴 인덱스.
		int patternIndex = 0;

		// 검출 문자열에서 패턴 문자열과 동일한 문자 수 확인.
		while (patternIndex < patternLength
			&& text[ix + patternIndex] == pattern[patternIndex])
		{
			++patternIndex;
		}

		if (patternIndex == patternLength)
		{
			return ix;
		}
	}

	// 실패 시 -1 반환.
	return -1;
}

// 최댓값 찾기.
//int FindMaxValue(const int array[], const int length)
int FindMaxValue(const int* array, const int length)
{
	// 최댓값 저장할 변수.
	int maxValue = array[0];

	// 배열 순회하면서 저장된 값보다 크면 교체.
	for (int ix = 1; ix < length; ++ix)
	{
		if (array[ix] > maxValue)
		{
			maxValue = array[ix];
		}
	}

	return maxValue;
}

// 배열에서 원하는 값 찾아서 인덱스 반환하는 함수.
// 배열이 함수로 전달되면 배열이 아니라 포인터(주소).
int FindValueIndex(const int array[], const int length, const int target)
{
	int ptrSize = sizeof(array);

	// 배열을 순회하면서 값 찾기.
	for (int ix = 0; ix < length; ++ix)
	{
		// 배열의 원소가 찾는 값인지 확인.
		if (array[ix] == target)
		{
			return ix;
		}
	}

	// 배열을 모두 찾아봤는데 검색에 실패했으면 -1 반환.
	return -1;
}

int main()
{
	// 배열.
	const int array[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
	const int length = sizeof(array) / sizeof(array[0]);
	const int target = 0;

	// 인덱스 검색.
	int result = FindValueIndex(array, length, target);

	if (result != -1)
	{
		std::cout << "검색 성공. 인덱스: " << result << "\n";
	}
	else
	{
		std::cout << "검색 실패.\n";
	}

	// 최댓값 검색.
	int maxValue = FindMaxValue(array, length);
	std::cout << "최댓값: " << maxValue << "\n";

	int resultIndex = FindPatternIndex("ronnie", "nie");
}