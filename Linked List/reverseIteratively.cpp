// Author : Deepdarshan
//Program for reversing a linked list by iterative method

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

void insert(Node **head, ll data, ll pos)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
    }
    else if (pos == 0)
    {
        temp->next = *head;
        *head = temp;
    }
    else
    {
        Node *temp1 = *head;
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

void reverse(Node **head)
{
    Node *prev, *curr, *next;
    curr = *head;
    prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = curr;
    // curr->next = prev;
}

void print(Node **head)
{
    Node *temp = *head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *A = NULL;
    ll data;
    insert(&A, 2, 0);
    insert(&A, 9, 1);
    insert(&A, 3, 2);
    insert(&A, 1, 1);
    insert(&A, 5, 3);
    insert(&A, 6, 7);
    insert(&A, 4, 4);
    insert(&A, 8, 6);
    insert(&A, 0, 0);
    insert(&A, -1, -1);
    print(&A);
    reverse(&A);
    print(&A);
    return 0;
}