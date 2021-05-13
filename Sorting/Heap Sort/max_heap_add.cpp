// Author : Deepdarshan
//Program for adding a number in a given max heap

#include <bits/stdc++.h>
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

int main()
{
    ll size, n;
    cout << "Enter the size of your Max Heap: ";
    cin >> size;
    ll A[size + 1], max_heap[size + 2];
    cout << "Enter the elements: " << endl;
    For(j, 1, size + 1, 1)
    {
        cin >> A[j];
    }
    cout << "Enter the element you want to add to heap: ";
    cin >> n;
    /*
       if index of node is: i
       then
       it's left child is at: 2*i
       it's right child is an: 2*i + 1
       and it's parent is at floor(i/2)
    */
    memset(max_heap, 0, sizeof(max_heap));
    //Print
    For(i, 1, size + 1, 1)
    {
        cout << max_heap[i] << " ";
    }
    cout << endl;
    max_heap[0] = LLONG_MAX;
    For(i, 1, size + 1, 1)
    {
        max_heap[i] = A[i];
    }
    max_heap[size + 1] = n;
    ll node = size + 1;
    while (1)
    {
        ll parent = floor(node / 2);
        if (max_heap[node] > max_heap[parent])
        {
            //cout << "SWAP" << endl;
            swap(node, parent, max_heap);
            node = parent;
        }
        else
        {
            break;
        }
    }
    For(i, 1, size + 2, 1)
    {
        cout << max_heap[i] << "  ";
    }
    cout << endl;
    return 0;
}