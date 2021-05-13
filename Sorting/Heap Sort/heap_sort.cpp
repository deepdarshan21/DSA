// Author : Deepdarshan
//Program for sorting given set of number using Heap Sort

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

int main()
{
    cout << "Enter the size of array: ";
    ll size;
    cin >> size;
    size += 1;
    ll A[size];
    cout << "Enter the elements of Array: ";
    For(i, 1, size, 1)
    {
        cin >> A[i];
    }

    //Add elements into heap
    ll heap[size];
    memset(heap, 0, sizeof(heap));
    heap[0] = LLONG_MAX;
    ll heap_size = 0, node1 = 0;
    For(i, 1, size, 1)
    {
        node1 += 1;
        heap[node1] = A[i];
        heap_size += 1;
        ll node = node1;
        while (1)
        {
            ll parent = floor(node / 2);
            if (heap[node] > heap[parent])
            {
                //cout << "SWAP" << endl;
                swap(node, parent, heap);
                node = parent;
            }
            else
            {
                break;
            }
        }
    }

    //Delete and sort
    For(i, 1, size - 1, 1)
    {
        swap(1, heap_size, heap);
        heap_size = heap_size - 1; //deletion of root element
        ll node = 1;
        ll left_child, right_child, max_child, parent;
        while (1)
        {
            parent = node;
            left_child = node * 2;
            right_child = node * 2 + 1;
            if (right_child <= heap_size)
            {
                max_child = heap[left_child] > heap[right_child] ? left_child : right_child;
            }
            else if (left_child == heap_size)
            {
                max_child = left_child;
            }
            else
            {
                break;
            }

            if (heap[parent] < heap[max_child])
            {
                swap(parent, max_child, heap);
                node = max_child;
            }
            else
            {
                break;
            }
        }
    }

    //Print
    For(i, 1, size, 1)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
    cout << "Press any key to exit...";
    char ch = getch(); // hold screen for .exe file
    return 0;
}
