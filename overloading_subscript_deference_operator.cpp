#include<iostream>

using namespace std;

class charBufCls {
	char* dStr;
public:
	charBufCls() { dStr = nullptr; }
	charBufCls(const char* xStr) 
	{
		int len = strlen(xStr);
		cout << "len is: " << len << endl;
		dStr = new char[len + 1];
		strcpy_s(dStr, len + 1, xStr); //check it is len + 1
	}

	//Impl1. If this is only char* then you can't do (*ob1) = *ob2 as it won't be a lvalue.
	char*& operator * ()
	{
		return (this->dStr);
	}

	char* operator -> ()
	{
		return (dStr);
	}
};

void overloading_subscript_dereference_op()
{
	charBufCls ob("Hello");
	cout << "Contents of charBufCls object ob: " << (*ob) << endl; //operator overloading.

	charBufCls ob2("niklo");
	(*ob) = (*ob2);
	//(*ob) = "Hello World";
	cout << "Contents of charBufCls object ob: " << (*ob) << endl;
}