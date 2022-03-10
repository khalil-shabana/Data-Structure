#include <iostream>
#include <string>
#include<math.h>
#include <stack>
using namespace std;


void print(stack <int> stk);
void decimal_to_binary(int d);
void binary_to_decimal(int b);

int main()
{
	
	while(1)
	{
		char starting_choice = ' ';
		char operation = ' ';
		cout << "New operation (y/n) ? ";
		cin >> starting_choice;

		if (starting_choice == 'n' || starting_choice == 'N')
			break;
		else if (starting_choice == 'y' || starting_choice == 'Y')
		{
			cout << "Press <1> to convert from decimal to binary" << endl;
			cout << "Press <2> to convert from binary to decimal" << endl;
			cin >> operation;
			if(operation=='1')
			{ 
				int decimal = 0;
				cout << "enter a decimal number : ";
				cin >> decimal;
				cout << "Output :\n";
				decimal_to_binary(decimal);
			}
			else
			{
				int binary = 0;
				cout << "enter a binary number : ";
				cin >> binary;
				cout << "Output :-\n";
				binary_to_decimal(binary);
			}
		}
		else
			cout << "Error !! " << endl;
	
	}
	return 0;
}

void print(stack <int> stk)
{
	int arr[10]{}; //initialized 
				  //512   256   128   64   32   16   8   4   2   1
	for (int i = stk.size(); i>=1; i--)
	{
		arr[i-1] = stk.top();
		cout << arr[i-1] <<" ";
		stk.pop();
	}
	cout << "\n-----------------------------------" << endl;

}

void decimal_to_binary(int d)
{
	stack <int> stk;
	if (d == 0)
		stk.push(0);
	while (d >=1)
	{ 
		if (d % 2 == 0)
		{
			stk.push(0);
			d /= 2;
		}
		else
		{
			stk.push(1);
			d /= 2;
		}
	}
	print(stk);
}

void binary_to_decimal(int b)
{
	int decimal=0, i=0, r;
	while (b != 0) 
	{
		r = b % 10;
		b /= 10;
		decimal += r * pow(2, i);
		i++;
	}
	cout << decimal << endl;
}