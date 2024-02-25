#include "List.cpp"
#include "String.h"
#include "Stack.cpp"
class Calculator
{
private:
	List<String> tokens;
	int tokennum;
	int errCode;	// 오류:1
	int value; // 계산된 값
	Stack<String> stk;
	String postfix; //후위 표기식 = 최초 공백으로 초기화
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

