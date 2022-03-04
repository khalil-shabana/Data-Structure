#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

class stack 
{
private:
	int data[SIZE];
	int top;

public:
	stack()
	{
		top = -1;
	}

	int full()
	{
		if (top == SIZE - 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int empty()
	{
		if (top == -1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	void push(int d)
	{
		if (full())
		{
			cout << "Stack Overflow!!" << endl;
		}
		else
			data[++top] = d;
	}
	
	void pop()
	{
		if(empty())
		{
			cout << "Stack is Empty" << endl;
		}
		else
		{
			top--;
		}
	}

	void show()
	{
		if(empty())
		{
			cout << "Stack is Empty" << endl;
		}
		else
		{
			int i;
			for (i=top ;i >= 0;i--) 
			{
				cout << data[i] << endl;
			}
		}
		cout << "--------------------------" << endl;
	}

	int top_element()
	{
		if (empty())
		{
			cout << "Stack is Empty" << endl;
		}
		else
		{
			return data[top];
		}
	}
};

int main()
{
	stack stk1;
	stk1.push(5);
	stk1.push(6);
	stk1.push(8);
	stk1.show();
	stk1.pop();
	stk1.show();
	stk1.pop();
	stk1.show();
	stk1.pop();
	stk1.show();
	stk1.push(5);
	stk1.push(6);
	stk1.push(7);
	stk1.push(8);
	stk1.push(9);
	stk1.push(10);
	stk1.push(11);
	stk1.push(19);
	stk1.push(120);
	stk1.push(12);
	stk1.show();
	stk1.push(12);



	return 0;
}