// Author : Deepdarshan
//Program for adding any element in the beginning  of linked list

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

void insert(Node **head, ll data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = *head;
    *head = temp;
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
    cout << "Enter the elements that you want to add in the linked list in starting position(to stop write '-1'): ";
    ll data;
    do
    {
        cin >> data;
        insert(&A, data);
    } while (data != -1);
    print(&A);
    return 0;
}