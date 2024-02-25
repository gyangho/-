#pragma once
class String
{
	friend class Calculator;
private:
	char* buffer;
	int length;
	int size;
	String(int m);
public:
	String();
	String(String&);
	String(char* init, int m);
	~String();
	//String& operator=(const String&);
	int Length();
	String Concat(String t);
	void Print();
};
