#include "Calculator.h"
#include <iostream>

using namespace std;

int main()
{
	char expr[1000];
	for (int i = 0; i < 1000; i++)
		expr[i] = '!';
	Calculator c;

	cout << "수식을 입력하시오 : ";
	cin.getline(expr, 1000);

	c.setExpression(expr);
	return 0;
}