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
		cout << "������ +,/,= �� �ϳ��� �Է����ּ���.\n�����Ϸ��� e�� �Է����ּ���\n>> ";
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
				cout << "RECT1�� RECT2�� �����մϴ�!" << endl;
			else
				cout << "RECT1�� RECT2�� �������� �ʽ��ϴ�" << endl;
			break;
		default:
			break;
		}
		printf("\n");
	}
	return 0;
} 