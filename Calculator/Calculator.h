#include "List.cpp"
#include "String.h"
#include "Stack.cpp"
class Calculator
{
private:
	List<String> tokens;
	int tokennum;
	int errCode;	// ����:1
	int value; // ���� ��
	Stack<String> stk;
	String postfix; //���� ǥ��� = ���� �������� �ʱ�ȭ
	String makePostFix();
	//int evaluation();

public:
	Calculator();
	~Calculator();
	void stkOut(int i);
	//int getErrorCode();
	int setExpression(const char* expr);
	//String getPostFix();
	//int getValue();
};

