// Author : Deepdarshan
//Program implementation of Doubly Linked List

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
    Node *prev;
    ll data;
    Node *next;
};

void insert(Node **head, ll data, ll pos)
{
    Node *temp;
    temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if (*head == NULL)
    {
        temp->next = *head;
        *head = temp;
        temp->prev = NULL;
        return;
    }
    if (pos == 0)
    {
        temp->next = *head;
        (*head)->prev = temp;
        temp->prev = NULL;
        *head = temp;
        return;
    }
    Node *temp1;
    temp1 = *head;
    For(i, 0, pos - 1, 1)
    {
        temp1 = temp1->next;
    }
    if (temp1->next != NULL)
    {
        temp1->next->prev = temp;
    }
    temp->next = temp1->next;
    temp->prev = temp1;
    temp1->next = temp;
}

void deleteNode(Node **head, ll data)
{
    Node *temp;
    temp = *head;
    if (temp->data == data)
    {
        *head = temp->next;
        (*head)->prev = temp->prev;
        return;
    }
    while (temp->data != data)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        temp->prev->next = NULL;
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void printForward(Node *head)
{
    Node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printBackward(Node *a)
{
    if (a == NULL)
    {
        return;
    }
    Node *temp = a;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    Node *A;
    A = NULL;
    ll data, pos;
    cout << "INSERTION STARTED(data & pos)" << endl;
    cin >> data >> pos;
    do
    {
        insert(&A, data, pos);
        // printForward(A);
        cin >> data >> pos;
    } while (data != -1);
    printForward(A);
    printBackward(A);
    // cout << endl;
    cout << "DELETION STARTED(data)" << endl;
    cin >> data;
    do
    {
        deleteNode(&A, data);
        // printForward(A);
        cin >> data;
    } while (data != -1);
    printForward(A);
    printBackward(A);
    // cout << endl;
    return 0;
}