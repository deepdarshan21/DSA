// Author : Deepdarshan
//Program for reversing a Linked List Recursively

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

Node *head;

void insert(/* Node **head,  */ ll data, ll pos)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else if (pos == 0)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        Node *temp1 = head;
        while (temp1->next != NULL)
        {
            pos -= 1;
            if (pos == 0)
            {
                break;
            }
            temp1 = temp1->next;
        }
        if (pos == 0)
        {
            temp->next = temp1->next;
            temp1->next = temp;
        }
        if (temp1->next == NULL)
        {
            temp1->next = temp;
            temp->next = NULL;
        }
    }
}

void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverse(Node *a)
{
    if (a->next == NULL)
    {
        head = a;
        return;
    }
    reverse(a->next);
    Node *b;
    b = a->next;
    b->next = a;
    a->next = NULL;
}

int main()
{
    // Node *A = NULL;
    ll data;
    insert(2, 0);
    insert(9, 1);
    insert(3, 2);
    insert(1, 3);
    insert(5, 4);
    insert(6, 5);
    insert(4, 6);
    insert(8, 7);
    insert(0, 8);
    insert(-1, -1);
    print();
    reverse(head);
    print();
    return 0;
}