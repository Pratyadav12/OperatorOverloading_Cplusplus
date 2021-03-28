#include<iostream>

using namespace std;

class Array {
	int* dArr;
	int dSize;
public:
	Array() { dArr = nullptr; dSize = 0; }
	Array(int* p, int xSize) {
		if (p != nullptr)
		{
			dSize = xSize;
			dArr = new int[xSize];
			for (int i = 0; i < xSize; i++)
			{
				dArr[i] = p[i];
			}
		}	
	}

	int& operator [](int xIdx)
	{
		if (xIdx >= dSize)
		{
			cout << "Array index out of bounds" << endl;
		}

		return (dArr[xIdx]);
	}
};


void overloading_subscript_op()
{
	int p[] = { 1, 2, 3, 4 };
	Array ob1(p, 4);

	cout << "Content of arr at idx 1: " << ob1[1] << endl;

	ob1[1] = 5;

	cout << "Content of arr at idx 1: " << ob1[1] << endl;
}