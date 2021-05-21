// Program for finding Maximum and Minimum

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
        print(A->left);
        cout << A->data << "  ";
        print(A->right);
    }
}
int findMin(Node **root)
{
    Node *temp;
    temp = *root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}
int findMax(Node *A)
{
    if (A->right == NULL)
        return A->data;
    else
        findMax(A->right);
}

int main()
{
    Node *root = NULL;
    insert(15, &root);
    insert(10, &root);
    insert(20, &root);
    insert(8, &root);
    insert(12, &root);
    insert(17, &root);
    insert(25, &root);
    print(root);
    cout << endl;
    cout << findMin(&root) << endl;
    cout << findMax(root) << endl;
    cout << endl;
    return 0;
}