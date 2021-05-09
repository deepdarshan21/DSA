// Author : Deepdarshan
//Program of stack using Linked List

#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
typedef long long int ll;
#define For(i, a, n, k) for (ll i = a; i < n; i += k)
void swap(ll i, ll j, ll A[])
{
    ll temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

struct Node
{
    ll data;
    Node *next;
};

void push(Node **head, ll x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

void pop(Node **head)
{
    *head = (*head)->next;
}

void top(Node **head)
{
    cout << "Top Value: " << (*head)->data << endl;
}

void isEmpty(Node **head)
{
    if (*head != NULL)
    {
        cout << "Not Empty" << endl;
    }
    else
    {
        cout << "Empty" << endl;
    }
}
void print(Node *A)
{
    if (A != NULL)
    {
        print(A->next);
        cout << A->data << "  ";
    }
}

int main()
{
    cout << "PROGRAM FOR STACK OPERATIONS USING LINKED LIST" << endl;
    Node *A = NULL;
    cout << endl
         << "AVAILABLE OPERATIONS:" << endl
         << "1. Push" << endl
         << "2. Pop" << endl
         << "3. Top" << endl
         << "4. isEmpty" << endl
         << "5. Print" << endl
         << "6. Exit" << endl;
    string input;
    while (1)
    {
        cout << "Enter Operation Name: " << endl;
        cin >> input;
        if (input.compare("Push") == 0)
        {
            ll pushInput;
            cout << "     Enter the number: ";
            cin >> pushInput;
            push(&A, pushInput);
        }
        else if (input.compare("Pop") == 0)
        {
            pop(&A);
        }
        else if (input.compare("Top") == 0)
        {
            top(&A);
        }
        else if (input.compare("isEmpty") == 0)
        {
            isEmpty(&A);
        }
        else if (input.compare("Print") == 0)
        {
            print(A);
            cout << endl;
        }
        else if (input.compare("Exit") == 0)
        {
            break;
        }
        else
        {
            cout << "Invalid Choice!" << endl;
        }
    }
    print(A);
    cout << endl;
    char ch = getch();
    return 0;
}