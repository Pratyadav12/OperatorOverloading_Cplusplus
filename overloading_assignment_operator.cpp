#include<iostream>

using namespace std;

class charBufCls {
	char* dStr;
	int dSize;
public:
	charBufCls() { dStr = nullptr; dSize = 0; }
	charBufCls(const char* xStr)
	{
		if (xStr)
		{
			int len = strlen(xStr);
			dStr = new char[len + 1];
			dSize = len;
			strcpy_s(dStr, len + 1, xStr);
		}
	}

	charBufCls& operator = (const charBufCls& p2)
	{
		/*a) This if-check is for self assignment. For ex: if someone does ob1 = ob1, in that case we will return the same ptr. 
		  b) Also suppose this if check was not there and you say, even if self assingment is costly then also I would do that, then in that case, you should not delete dStr first
		     as this.dStr and p2.dStr are same. To handle that, delete dStr only at the end.*/
		if (this == &p2) 
			return *this;
		if (dStr)        //delete dStr if it already points to something and then allocate new memory and assign contents to it.
			delete dStr;
		int len = strlen(p2.dStr);
		dStr = new char[len + 1];
		dSize = len;
		strcpy_s(dStr, len + 1, p2.dStr);
	}

	char* getStr() { return dStr; }

	~charBufCls()
	{
		if (dStr)
			delete dStr;
	}
};


void overloading_assignment_op()
{
	charBufCls ob2;
	
	{
		charBufCls ob1("Hello");
		ob2 = ob1;
	}

	cout << "Contents of ob2 now becomes: " << ob2.getStr() << endl; //this also shows deep copy occuring as ob1 and its contents are invalid after the bracket scope
}