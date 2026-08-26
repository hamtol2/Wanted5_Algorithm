#include <iostream>

// 거듭 제곱 재귀 함수.
int Power(int x, int y)
{
	// 종료 조건.
	if (y == 0)
	{
		return 1;
	}

	// 범위를 줄여가면서 재귀 함수 호출.
	return x * Power(x, y - 1);
}


// 1부터 지정한 수까지의 합을 구하는 재귀 함수.
int Sum(int number)
{
	// 종료 조건.
	if (number == 1)
	{
		return 1;
	}

	// 문제의 범위를 줄여가면서 재귀적으로 호출.
	return number + Sum(number - 1);
}

int main()
{
	// 2의 8승 = 256.
	// 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192...
	int power = Power(2, 8);

	// 1부터 5까지의 합.
	const int target = 5;
	int result = Sum(target);
	int check = 1 + 2 + 3 + 4 + 5;

	std::cout << "결과: " << result << "\n";
	std::cout << "비교: " << check << "\n";
}