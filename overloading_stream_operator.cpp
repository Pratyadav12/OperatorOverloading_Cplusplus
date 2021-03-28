#include<iostream>

using namespace std;

class Complex
{
	int real;
	int imag;
public:
	Complex() { real = 0; imag = 0; }
	Complex(int r, int im): real(r), imag(im) {}
	friend ostream& operator << (ostream& out, Complex& p1);
	friend istream& operator >> (istream& in, Complex& p2);
};

ostream& operator << (ostream& out, Complex& p1)
{
	cout << "Printing using overloaded << op" << endl;
	out << "real: " << p1.real << " imag: " << p1.imag << endl;
	return out;
}

istream& operator >> (istream& in, Complex& p2)
{
	cout << "Input using overloaded >> op" << endl;
	cout << "Enter real part" << endl;
	in >> p2.real;

	cout << "Enter imag part" << endl;
	in >> p2.imag;

	return in;
}

void overload_stream()
{
	Complex c1;

	cin >> c1;

	cout << c1;
}

void overloading_stream_op()
{
	overload_stream();
}