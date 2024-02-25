#include "String.h"
#include <iostream>

using namespace std;
String::String() :String(10)
{

}
String::String(String& s) : String(s.length + 1)
{
	for (int i = 0; i < s.length; i++)
		buffer[i] = s.buffer[i];
	buffer[s.length] = '\0';
	length = s.length;
}
String::~String()
{
	//cout << "¼Ò¸êÀÚ È£Ãâ\n";
	//delete[] buffer;
}
String::String(int m)
{
	size = m;
	buffer = new char[m];
	length = 0;
}
String::String(char* init, int m) :String(m + 1)
{
	for (int i = 0; i < m; i++)
		buffer[i] = init[i];
	buffer[m] = '\0';
	length = m;
}

String String::Concat(String t)
{
	String result(length + t.length + 1);
	for (int i = 0; i < length; i++)
		result.buffer[i] = buffer[i];
	for (int i = 0; i < t.length; i++)
		result.buffer[length + i] = t.buffer[i];
	result.buffer[length + t.length] = '\0';
	result.length = length + t.length;

	return result;
}
/*String& String::operator=(const String& s)
{
	delete[] buffer;
	buffer = new char[s.length + 1];
	for (int i = 0; i < s.length; i++)
		buffer[i] = s.buffer[i];
	buffer[s.length] = '\0';
	length = s.length;
	return *this;
}*/
int String::Length()
{
	int i = 0;
	while (buffer[i] != '\0')
		i++;
	return i;
}
void String::Print()
{
	cout << buffer << "   ";
}
