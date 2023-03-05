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

	// ���� �Լ� ����
	//friend Point2D operator+(const Point2D& left, const Point2D& right)
	//{

	//	Point2D pt;
	//	pt.mX = left.mX + right.mX;
	//	pt.mY = left.mY + right.mY;

	//	return pt;
	//};

	// ��� �Լ� ����
	Point2D operator+(const Point2D& right)	// �ϳ��� this�� �ޱ� ������
	{										// const �ϳ��� �ʿ�

		Point2D pt;							// �ν��Ͻ��� ��� mX, mY
		pt.mX = this->mX + right.mX;		
		pt.mY = this->mY + right.mY;		
	 // ��� �Լ� �ȿ��� ��� �ν��Ͻ��� 
	 //	Ŭ������ ��������, private���� ���� �����ϴ�
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