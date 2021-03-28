#include<iostream>

using namespace std;

class Complex
{
	int real;
	int imag;
public:
	Complex() { real = 0; imag = 0; }
	Complex(int r, int im) : real(r), imag(im) {}
//	friend Complex& operator + (Complex& p1, Complex& p2); overloading + as global op
/*	Complex operator + (Complex& p1, Complex& p2) //won't even compile as two parameters are passed. Below is the right impl.
	{
		Complex c1;
		c1.real = p1.real + p2.real;
		c2.imag = p1.imag + p2.imag;
		return c1;
	}*/

	//This compiles fine. As call c1 + c2 is implied as c1(c2) by the compiler. So we use this->ptr to use values of c1 and c2 is passed as arg to it.
	Complex operator + (Complex& p2)
	{
		Complex c1;
		c1.real = this->real + p2.real;
		c1.imag = this->imag + p2.imag;
		return c1;
	}

	void print() { cout << "real: " << real << " imag: " << imag << endl; }
};

/*Complex& operator + (Complex& p1, Complex& p2)
{
	Complex ob1;
	ob1.real = p1.real + p2.real;
	ob1.imag = p1.imag + p2.imag;

	return ob1;
}*/

void overloading_add_op()
{
	Complex c1(4, 2);
	Complex c2(2, 4);

	Complex c3;
	c3 = c1 + c2;
	c3.print();
}