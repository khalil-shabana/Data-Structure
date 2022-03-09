#include <iostream>
#include <stack>
#include <string>
using namespace std;

string Infix_to_Postfix(string expression);
int priority(char op);
bool is_Operator(char s);
 
int main()
{
	cout << "Welcome to << infix to postfix conversion program >>" << endl;
	cout << "You can enter your expression in infix form to convert it to postfix form " << endl;

	while (1)
	{
		
		string expression;
		string output;
		string ch = " ";
		cout << "Enter a new expression ? y/n ? ";
		getline(cin,ch);
		
		if (ch == "n" || ch == "N")
			break;
		else if (ch == "y" || ch == "Y")
		{
			getline(cin,expression);
			output = Infix_to_Postfix(expression);
			cout << "OUTPUT : " << output << endl;

		}
		else
			cout << "Error !! " << endl;
	}

	return 0;
}

string Infix_to_Postfix(string expression)
{
	stack <char> stk;
	string output = "";
	unsigned int i;
	for (i = 0;i < expression.length();i++)
	{
		if (expression[i] == ' ') 
			continue;
		else if (isdigit(expression[i]) || isalpha(expression[i]))
		{
			output += expression[i];
		}
		else if (expression[i] == '(')
			stk.push(expression[i]);
		else if (expression[i]== ')')
		{
			while (stk.top() != '(')
			{
				output += stk.top();
				stk.pop();
			}
			stk.pop();
		}
	
		else
		{
			if (!is_Operator(expression[i]))
			{
				cout << "Error:: There is Non-arithmetic operator " << endl;
				exit (0) ;
			}
			else
			{
				while (!stk.empty() && is_Operator(expression[i]) && priority(expression[i]) <= priority(stk.top()))
				{
					output += stk.top();
					stk.pop();

				}
				stk.push(expression[i]);
			}
			
		}
	}
	while (!stk.empty())
	{
		output += stk.top();
		stk.pop();
	}
	return output;
}

int priority(char op)
{
	int weight = 0;
	switch (op)
	{
	case '+':
	case '-':
		weight = 1;
		break;

	case '*':
	case '/':
	case '%':
		weight = 2;
		break;

	case '^':
		weight = 3;
		break;	
	}
	return weight;
}

bool is_Operator(char s)
{
	if (s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '%' )
		return true;
	else
		return false;
}
