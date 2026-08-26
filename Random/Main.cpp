#include <iostream>
#include <cstdlib>
#include <ctime>

// 범위를 지정해서 특정 범위의 정수 난수를 반환하는 함수.
int RandomRange(int min, int max)
{
	// 나머지 연산을 활용한 방법.
	//const int diff = (max - min) + 1;
	//return (rand() % diff) + min;

	// 나누기 연산을 활용한 방법.
	const int diff = (max - min) + 1;
	return ( (rand() * diff) / (RAND_MAX + 1) ) + min;
}

int main()
{
	// 현재 시간 값을 받음.
	// 종자값을 가변적으로 설정해야 함.
	// 많은 경우에 시간을 활용.
	int64_t seed = time(nullptr);

	// 종자값(seed).
	srand(static_cast<uint32_t>(seed));


	const int count = 5;
	for (int ix = 0; ix < count; ++ix)
	{
		//std::cout << "Random Number: " << rand() << "\n";
		std::cout << "Random Number: " << RandomRange(1, 10) << "\n";
	}
}