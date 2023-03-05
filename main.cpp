#include <iostream>

class Point2D
{
private:
	int mX;
	int mY;

public:
	Point2D() : mX{ 0 }, mY{ 0 }
	{
	}

	Point2D(int x, int y) : mX{ x }, mY{ y }
	{
	}

	void Print()
	{
		std::cout << "(" << mX << ", " << mY << ")" << std::endl;
	}

	// 전역 함수 버전
	//friend Point2D operator+(const Point2D& left, const Point2D& right)
	//{

	//	Point2D pt;
	//	pt.mX = left.mX + right.mX;
	//	pt.mY = left.mY + right.mY;

	//	return pt;
	//};

	// 멤버 함수 버전
	Point2D operator+(const Point2D& right)	// 하나는 this로 받기 때문에
	{										// const 하나만 필요

		Point2D pt;							// 인스턴스의 멤버 mX, mY
		pt.mX = this->mX + right.mX;		
		pt.mY = this->mY + right.mY;		
	 // 멤버 함수 안에서 어떠한 인스턴스든 
	 //	클래스가 정해지면, private으로 접근 가능하다
		return pt;
	}
};	

int main()
{
	Point2D pt1(2, 3);
	Point2D pt2(4, 5);
	Point2D pt3;
	pt3 = pt1 + pt2;

	Point2D pt4;
	pt4 = (pt1 + pt2) + pt3;		
	pt4.Print();					
}