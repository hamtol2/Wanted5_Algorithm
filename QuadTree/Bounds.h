#pragma once

// 사각 영역 표현하는 클래스.
class Bounds
{
public:
	Bounds(int x, int y, int width = 1, int height = 1)
		: x(x), y(y), width(width), height(height)
	{
	}

	// Getter.
	int GetX() const { return x; }
	int GetY() const { return y; }
	int GetWidth() const { return width; }
	int GetHeight() const { return height; }

	// 오른쪽 및 아래쪽 경계 Getter.
	int GetXMax() const { return x + width; }
	int GetYMax() const { return y + height; }

	// Setter(필요시 추가).

	// 점이 영역 안에 포함되는지 확인하는 함수.
	bool Contains(int pointX, int pointY) const
	{
		return pointX >= x && pointX < GetXMax()
			&& pointY >= y && pointY < GetYMax();
	}

	// 다른 사각형이 현재 영역에 포함되는지 확인.
	bool Contains(const Bounds& other) const
	{
		return other.x >= x && other.GetXMax() < GetXMax()
			&& other.y >= y && other.GetYMax() < GetYMax();
	}

	// 다른 사각형과 겹치는지 확인하는 함수.
	bool Intersects(const Bounds& other) const
	{
		return other.x < GetXMax() && other.GetXMax() > x
			&& other.y < GetYMax() && other.GetYMax() > y;
	}

private:
	// 위치(콘솔 좌표계 기준).
	int x = 0;
	int y = 0;

	// 크기.
	int width = 1;
	int height = 1;
};