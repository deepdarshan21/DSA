// Author : Deepdarshan
//Program for creating a Linked List(Basic One):adding new element to end

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

void insert(Node *A, ll data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    /* ll i = 0;
    if (A->next == NULL)
    {
        A = temp;
        // temp->next = NULL;
        i += 1;
    } */

    Node *temp1 = A;
    ll i = 1;
    while (temp1->next != NULL)
    {
        cout << " Yes ";
        i += 1;
        temp1 = temp1->next;
    }
    temp1->next = temp;
    // temp->next = NULL;
    cout << endl;

    cout << "Inserted " << i << endl;
}

void print_list(Node *A)
{
    cout << "Print Start:" << endl;
    Node *temp = A;
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
    cout << "Enter the set of data(if your end enter \"-1\": ";
    ll data;
    cin >> data;
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    A = temp;
    while (1)
    {
        cin >> data;
        if (data == -1)
            break;
        insert(A, data);
    }
    print_list(A);
    return 0;
}