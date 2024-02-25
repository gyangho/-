#include <iostream>
#include "REctangle.h"

using namespace std;


int main()
{
	char Input=0;
	bool equal;
	Rectangle rect1;
	Rectangle rect2;
	Rectangle result;
	cout << "RECT1\n";
	rect1.read();
	cout << "RECT2\n";
	rect2.read();

	while (Input != 'e')
	{
		cout << "연산자 +,/,= 중 하나를 입력해주세요.\n종료하려면 e를 입력해주세요\n>> ";
		cin >> Input;
		switch (Input)
		{
		case '+':
			result = rect1 + rect2;
			cout << "<<<<<<<<RESULT>>>>>>>>" << endl;
			cout << result;
			result.getArea();
			break;
		case '/':
			result = rect1 / rect2;
			cout << "<<<<<<<<RESULT>>>>>>>>" << endl;
			cout << result;
			result.getArea();
			break;
		case '=':
			equal = rect1 == rect2;
			if (equal == 1)
				cout << "RECT1과 RECT2는 동일합니다!" << endl;
			else
				cout << "RECT1과 RECT2는 동일하지 않습니다" << endl;
			break;
		default:
			break;
		}
		printf("\n");
	}
	return 0;
} 