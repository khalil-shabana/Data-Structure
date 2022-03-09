#include <iostream>
#include <string>
#include<math.h>
#include <stack>

using namespace std;

float postfix_evaluate(string exp);
float math_operation(float op1, float op2, char operat);
bool is_Operator(char s);

int main()
{
	string postfix_expression = " ";
	
	while (1)
	{
		string ch = " ";
		cout << "Enter a new expression (y/n) ? ";
		getline(cin, ch);

		if (ch == "n" || ch == "N")
			break;
		else if (ch == "y" || ch == "Y")
		{
			cout << "Enter a Postfix Expression: ( e.g. 4 5 + )\n ";

			getline(cin, postfix_expression);
			cout << "Result : " << postfix_evaluate(postfix_expression) << endl;
		}
		else
			cout << "Error !! " << endl;
	}

	return 0;
}

bool is_Operator(char s)
{
	if (s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '%')
		return true;
	else
		return false;
}
float math_operation(float op1, float op2, char operat)
{
	switch (operat)
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	case '%':
		return (int)op1 % (int)op2;
	case '^':
		return pow(op1,op2);
	}
}
float postfix_evaluate(string exp)
{
	stack <float> stk;
	for (int i = 0;i < exp.length();i++)
	{
		if (isdigit(exp[i]))
			stk.push(exp[i] - '0');
		else if (exp[i] == ' ') continue;
		else if (!is_Operator(exp[i]))
		{		cout << "Error:: There is Non-arithmetic operator" << endl;
		exit(0);
		}
		else
		{
			float op2 = stk.top();
			stk.pop();
			float op1 = stk.top();
			stk.pop();
			float result = math_operation(op1, op2, exp[i]);
			stk.push(result);
		}
	}
	return stk.top(); //final answer
}