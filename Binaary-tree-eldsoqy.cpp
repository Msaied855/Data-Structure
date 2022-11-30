#include <iostream>
using namespace std;
// -->https://www.youtube.com/watch?v=FSYsHmW-zGg  This is the one who write the Removenode functions

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class BST
{
    void RemoveNodePrivate(int key, Node *parent);
    void RemoveMatch(Node *parent, Node *match, bool left);
    int FindSmallestPrivate(Node *ptr);

public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    Node *Insert(Node *root, int item)
    {
        if (root == NULL)
        {
            Node *newnode = new Node(item);
            root = newnode;
        }
        else if (item < root->data)
            root->left = Insert(root->left, item);
        else
            root->right = Insert(root->right, item);

        return root;
    }
    void Insert(int item)
    {
        root = Insert(root, item);
    }
    void RemoveNode(int key);
    int FindSmallest();
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
        if (p != NULL)
        {
            inOrder(p->left);
            cout << p->data << ' ';
            inOrder(p->right);
        }
    }
    void postOrder(Node *p)
    {
        if (p != NULL)
        {
            postOrder(p->left);
            postOrder(p->right);
            cout << p->data << ' ';
        }
    }
};

int main()
{
    int input = 0;
    BST btree;
    btree.Insert(45);
    btree.Insert(15);
    btree.Insert(79);
    btree.Insert(90);
    btree.Insert(10);
    btree.Insert(55);
    btree.Insert(12);
    btree.Insert(20);
    btree.Insert(50);
    btree.Insert(2);
    /*
                  45
            15          79
        10    20     55     90
      2    12      50
    */
    btree.preOrder(btree.root);
    cout << endl;
    cout << "the Smallest value in the tree is :- " << btree.FindSmallest() << endl
         << '\n';
    cout << "Enter the key value that you want to delete. Enter - to stop the process\n"
         << endl;
    while (input != -1)
    {
        cout << "Delete Node :- ";
        cin >> input;
        {
            if (input != -1)
            {
                cout << endl;
                btree.RemoveNode(input);
                btree.preOrder(btree.root);
                cout << endl;
            }
        }
    }
}
void BST::RemoveNode(int key)
{
    RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, Node *parent)
{
    if (root != NULL)
    {
        if (root->data == key)
        {
            cout << "this is root.i didn't implement this case yet.\n";
        }
        else
        {
            if (key < parent->data && parent->left != NULL)
            {
                parent->left->data == key ? RemoveMatch(parent, parent->left, true) : RemoveNodePrivate(key, parent->left);
            }
            else if (key > parent->data && parent->right != NULL)
            {
                parent->right->data == key ? RemoveMatch(parent, parent->right, false) : RemoveNodePrivate(key, parent->right);
            }
            else
            {
                cout << "The key :-" << key << " was not found in this tree\n";
            }
        }
    }
    else
        cout << "thr tree is empty.";
}

void BST::RemoveMatch(Node *parent, Node *match, bool left)
{
    Node *delptr;
    int matchkey = match->data;
    int SmallestinRightSupTree;

    // case 0 - 0 Children

    if (match->left == NULL && match->right == NULL)
    {
        delptr = match;
        left == true ? parent->left = NULL : parent->right = NULL;
        delete delptr;
    }
    // case 1 - 1 child
    else if (match->left == NULL && match->right != NULL)
    {
        left == true ? parent->left = match->right : parent->right = match->right;
        match->right = NULL;
        delptr = match;
        delete delptr;
    }
    else if (match->left != NULL && match->right == NULL)
    {
        left == true ? parent->left = match->left : parent->right = match->left;
        match->left = NULL;
        delptr = match;
        delete delptr;
    }
    // Case 2 - 2 Children
    else
    {
        SmallestinRightSupTree = FindSmallestPrivate(match->right);
        RemoveNodePrivate(SmallestinRightSupTree, match);
        match->data = SmallestinRightSupTree;
    }
}
int BST::FindSmallest()
{
    return FindSmallestPrivate(root);
}
int BST::FindSmallestPrivate(Node *ptr)
{
    if (root == NULL)
    {
        cout << "The Tree is empty\n";
        return -1000;
    }
    else
    {
        if (ptr->left != NULL)
        {
            return FindSmallestPrivate(ptr->left);
        }
        else
        {
            return ptr->data;
        }
    }
}
