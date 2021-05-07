// Author : Deepdarshan
//Program for adding any element in nth place in linked list

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
    cout << "Enter the elements and its position that you want to add in the linked list(to stop write '-1'): ";
    ll data, pos;
    do
    {
        cin >> data >> pos;
        insert(&A, data, pos);
        print(&A);
    } while (data != -1);
    print(&A);
    return 0;
}