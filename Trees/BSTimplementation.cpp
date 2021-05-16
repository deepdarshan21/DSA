// Program for implementing tree

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};

void insert(int data, Node **A)
{
    if (*A == NULL)
    {
        Node *temp;
        temp = new Node;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        *A = temp;
    }
    else if ((*A)->data >= data)
        insert(data, &(*A)->left);
    else
        insert(data, &(*A)->right);
}
void print(Node *A)
{
    if (A != NULL)
    {
        cout << A->data << "  ";
        print(A->left);
        print(A->right);
    }
}
bool binarySearch(Node *A, int x)
{
    bool ans = false;
    if (A != NULL)
    {
        if (A->data == x)
            ans = true;
        else if (A->data > x)
            ans = binarySearch(A->left, x);
        else
            ans = binarySearch(A->right, x);
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    insert(12, &root);
    insert(7, &root);
    insert(19, &root);
    insert(5, &root);
    insert(9, &root);
    insert(10, &root);
    print(root);
    cout << endl;
    cout << binarySearch(root, 9) << endl;
    cout << binarySearch(root, 1) << endl;
    return 0;
}