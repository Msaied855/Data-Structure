#include <iostream>
using namespace std;

struct Queue
{
    int val;
    Queue *next;
};
Queue *front = NULL, *rear = NULL;

void enqueue(int value);
void dequeue();
int peek();
void display();

int main()
{
    enqueue(5);
    enqueue(15);
    enqueue(25);
    enqueue(35);
    cout << "Peek:" << peek() << endl;
    dequeue();
    enqueue(45);
    display(); // 15 25 35 45
}
void enqueue(int value)
{

    Queue *newNode, *last;
    newNode = new Queue;
    newNode->val = value;
    newNode->next = NULL;

    if (front == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
void dequeue()
{
    if (front == NULL)
        cout << "Queue is Empty";
    else if (front == rear)
    {
        Queue *ptr = front;
        front = rear = NULL;
        delete (ptr);
    }
    else
    {
        Queue *ptr = front;
        front = front->next;
        delete (ptr);
    }
}
int peek()
{
    if (front == NULL)
        return -1; // i can't return massege here bcz we should return just number
    else
        return front->val;
}
void display()
{
    if (front == NULL)
        cout << "Queue is Empty.";
    Queue *curr = front;
    while (curr != NULL)
    {
        cout << curr->val << ' ';
        curr = curr->next;
    }
    cout << endl;
}