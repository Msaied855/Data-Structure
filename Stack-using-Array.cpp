
/*
    *Important NOTE*
    if you are going to use this (#include <bits/stdc++.h>) library
    so you can't name the array "stack"
    use another name which is "Stack" with capital 'S' in this code or use iostream library
    -Another note 


*/
#include <bits/stdc++.h>
using namespace std;
#define size 5
int Stack[5], top = -1;
void push(int value);
void pop();
int peek();
void display();




int main()
{
    push(5);                              // 5
    push(15);                             // 5 15
    push(20);                             // 5 15 20
    pop();                                // 5 15 -
    push(50);                             // 5 15 - 50

    if(peek()==-1)
        cout<<"Stack Underflow.";
    else    
        cout<<"peek :- "<<peek()<<endl; // printing the top elelment
  
    display();                            // the result should be 5 15 50
    return 0;
}
void push(int value)
{
    if (top == size - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        Stack[top] = value;
    }
}
void pop()
{
    if (top != -1)
        top--;
    
}
int peek()
{
    if (top == -1)
    {
         return -1;
    }
    else
            return Stack[top];
}
void display()
{
    if (top == -1)
    {
        cout << "Stack Underflow";
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            cout << Stack[i] << endl;
        }
    }
}
