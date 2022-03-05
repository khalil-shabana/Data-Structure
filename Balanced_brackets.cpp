#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool are_pair(char open, char close)
{
	if (open == '(' && close == ')')
		return true;
	else if (open == '{' && close == '}')
		return true;
	else if (open == '(' && close == ')')
		return true;
	else
		return false;
}

bool are_balanced(string exp)
{
	stack <char> open_brackets;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
		{
			open_brackets.push(exp[i]);
		}
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (open_brackets.empty() || !are_pair(open_brackets.top(), exp[i]))
				return false;
			else
				open_brackets.pop();
		}
	}
	return (open_brackets.empty()) ? true : false;
}

int main()
{
	cout << "Welcome to << Balanced brackets test >>" << endl;
	cout << "You can test your expression (if it's balanced or not)" << endl;
	cout << "To exit the test, click 'x' " << endl;
	while (1)
	{
	string expression;
	cout << "Enter your expression : ";
	getline(cin, expression);
	if (expression == "x" || expression == "X")
		break;
	else if (are_balanced(expression))
		cout << "Balanced" << endl;
	else
		cout << "Not Balanced" << endl;
	}
	return 0;
}