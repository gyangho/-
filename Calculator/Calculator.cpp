#define _CRT_SECURE_NO_WARNINGS
#include "Calculator.h"
#include <iostream>
#include <string.h>

bool is_digit(char* str)
{
	return atoi(str) != 0 || strcmp(str, "0") == 0;
}

Calculator::Calculator()
{
	String postfix(1);
	tokennum = 0;
	errCode = 0;
	value = 0;
}

Calculator::~Calculator()
{

}

void Calculator::stkOut(int i)
{
	while (1)
	{
		if (stk.IsEmpty() == 1)
			break;
		if (strcmp(stk.Top().buffer, "(") == 0)
		{
			cout << "in stkOut there is (\n";
			if (i == 1)
			{
				stk.Pop();
				cout << "pop\n";
			}
			break;
		}
		cout <<"stk.stack[top]== "<< stk.Top().buffer << endl;
		postfix=postfix.Concat(stk.Top());
		stk.Pop();
	}
}
String Calculator::makePostFix()
{
	for (int i = 0; i < tokennum; i++)
	{
		cout << "i :" << i << "\n";
		if (strcmp(tokens.items[i].buffer, ")")==0)
		{
			cout << "there is )\n";
			stkOut(1);
		}
		else if (is_digit(tokens.items[i].buffer))
		{
			cout << "number : "<< tokens.items[i].buffer<<"\n";
			postfix = postfix.Concat(tokens.items[i]);
		}
		else
		{
			while (1)
			{
				if (tokens.items[i].buffer[0] % 5 == 2)
						break;
				else if (strcmp(tokens.items[i].buffer, "(")==0)
					break;
				else
				{
					if (stk.IsEmpty())
						break;
					if (strcmp(tokens.items[i].buffer, "(") == 0)
						break;
					stkOut(0);
					break;
				}
			}
			cout << "sign " << tokens.items[i].buffer << "\n";
			stk.Push(tokens.items[i]);
		}
	}
	stkOut(0);
	return postfix;
}
/*int Calculator::evaluation()
{

}*/
/*
int Calculator::getErrorCode()
{

}
*/
int Calculator::setExpression(const char* expr)
{
	char* tmp;	
	tmp = strtok((char*)expr, " ");
	while (tmp != NULL)
	{
		String str(tmp, strlen(tmp));
		tokens.addItem(str);
		tmp = strtok(NULL, " ");
		tokennum++;
	}
	tokens.print();
	postfix = makePostFix();
	cout <<"Print postfix\n";
	postfix.Print();
	return 0;
}
/*
String Calculator::getPostFix()
{

}
int Calculator::getValue()
{

}
*/
