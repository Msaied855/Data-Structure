#include <iostream>
using namespace std;

#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
void enqueue(int value);
void dequeue();
void display();
int peak();

int main()
{
    enqueue(5);
    enqueue(5);
    enqueue(9);
    cout << peak() << endl;
    display();
    dequeue();
    cout << peak() << endl;
    display();
}

void enqueue(int value)
{
    if (rear != SIZE - 1)
    {
        queue[++rear] = value;
        if (front == -1)
            front++;
    }
    else
        cout << "This Queue is full." << endl;
}
void dequeue()
{
    if (rear == -1 || front > rear)
        cout << "Thies Queue is empty..";
    else
        front++;
}
void display()
{

    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << ' ';
    }
    cout << endl;
}
int peak()
{
    return queue[front];
}