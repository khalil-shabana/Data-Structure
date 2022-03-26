#include <iostream>
#include <string>
using namespace std;
#define MAX_SIZE 5

template <class t>
class Queue
{
private:
	int rear;
	int front;
	int length;
	t arr[MAX_SIZE];

public:
	Queue()
	{
		rear = MAX_SIZE - 1;
		front = 0;
		length = 0;
	}
	bool isEmpty()
	{
		if (length == 0)
			return true;
		else
			return false;
	}
	bool isFull()
	{
		if (length == MAX_SIZE)
			return true;
		else
			return false;
	}
	void Enqueue(t element)
	{
		if (isFull())
			cout << "Queue is overflow!\n";
		else
		{
			rear = (rear + 1) % MAX_SIZE;
			arr[rear] = element;
			length++;
		}
	}

	void Dequeue()
	{
		if (isEmpty())
			cout << "Queue is empty!\n";
		else
		{
			cout << "Data dequeued " << arr[front]<<endl;
			front = (front + 1) % MAX_SIZE;
			length--;
		}
	}

	t get_front()
	{
		if(!isEmpty())
			return arr[front];
	}

	t get_rear()
	{
		if (!isEmpty())
			return arr[rear];
	}

	void display()
	{
		if (isEmpty())
			cout << "Queue is empty!!\n";
		else
		{
			cout << "------ the queue content ------\n";
			for (int i = front;i != rear;i = (i + 1) % MAX_SIZE)
			{
				cout << arr[i] << endl;
			}
			cout << arr[rear] << endl;
		}
		
	}
};
int main()
{
	Queue <int> q1; //int can be any data type (char,string,float ...)
	q1.Enqueue(5);
	q1.display();
	q1.Enqueue(10);
	q1.display();
	q1.Enqueue(15);
	q1.display();
	q1.Enqueue(20);
	q1.display();
	q1.Enqueue(25);
	q1.display();
	q1.Enqueue(30);
	q1.display();
	q1.Dequeue();
	q1.display();
	q1.Dequeue();
	q1.Dequeue();
	q1.Dequeue();
	q1.Dequeue();
	q1.display();

	return 0;
}
