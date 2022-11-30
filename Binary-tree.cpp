#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left,*right;
   

    Node(int val)
    {
        data = val;

        left = NULL;
        right = NULL;
    }
};
Node *root = NULL;

void preOrder(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << ' ';
        preOrder(p->left);
        preOrder(p->right);
    }
}

void inOrder(Node *p)
{
    if(p !=NULL)
    {
        inOrder(p->left);
        cout<<p->data<<' ';
        inOrder(p->right);
    }

}
void postOrder(Node *p)
{
     if(p !=NULL)
    {
        postOrder(p->left);
        postOrder(p->right);
        cout<<p->data<<' ';
    }
}

int main()
{
    // creat the root
    root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /*
                 1 //Root Node
                / \
               2    3
              / \  / \
             4  5  6  7
    */
   
    inOrder(root);
    
}