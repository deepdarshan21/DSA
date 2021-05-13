// Author : Deepdarshan
//Program for deleting root element from the given max heap

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
    ll size;
    cout << "Enter the size of your Max Heap: ";
    cin >> size;
    ll A[size + 1];
    cout << "Now enter the elements of your Max Heap: ";
    For(i, 1, size + 1, 1)
    {
        cin >> A[i];
    }
    cout << "As we know that in Heaps we can only delete the element which is present in root, so we will delete: " << A[1] << " from the Heap." << endl;
    A[1] = A[size];
    A[size] = 0;
    size = size - 1; //deletion of root element
    ll node = 1;
    /*
       if index of node is: i
       then
       it's left child is at: 2*i
       it's right child is an: 2*i + 1
       and it's parent is at floor(i/2)
    */
    ll left_child, right_child, max_child, parent;
    while (1)
    {
        parent = node;
        left_child = node * 2;
        right_child = node * 2 + 1;
        if (right_child <= size)
        {
            max_child = A[left_child] > A[right_child] ? left_child : right_child;
        }
        else if (left_child == size)
        {
            max_child = left_child;
        }
        else
        {
            break;
        }

        if (A[parent] < A[max_child])
        {
            swap(parent, max_child, A);
            node = max_child;
        }
        else
        {
            break;
        }
    }
    For(i, 1, size + 1, 1)
    {
        cout << A[i] << "   ";
    }
    cout << endl;
    return 0;
}