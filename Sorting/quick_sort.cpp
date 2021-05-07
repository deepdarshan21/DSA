// Author : Deepdarshan
//Program for quick sort

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

void quickSort(ll i, ll j, ll *A)
{
    if (i < j)
    {
        // cout << "QuickSort Entered" << endl;
        ll pivot = i;
        ll start = i + 1, end = j - 1;
        while (start <= end)
        {
            // cout << "   While Loop Entered" << endl;
            /* if (A[start] > A[pivot] && A[end] < A[pivot])
            {
                swap(start, end, A);
            } */
            if (start < end)
            {
                swap(start, end, A);
            }
            // cout << "         Loop for \"Start\" Started" << endl;
            while (A[start] <= A[pivot])
            {
                start += 1;
            }
            // cout << "         Loop for \"Start\" Ended" << endl;
            // cout << "         Loop for \"End\" Started" << endl;
            while (A[end] > A[pivot])
            {
                end -= 1;
            }
            // cout << "         Loop for \"End\" Ended" << endl;
            /* if (start < end)
            {
                swap(start, end, A);
            } */
        }
        // cout << "While Loop Ended";
        swap(pivot, end, A);
        quickSort(i, end - 1, A);
        quickSort(end + 1, j, A);
    }
}

int main()
{
    ll A[] = {10, 16, 8, 12, 15, 6, 3, 9, 5, LLONG_MAX};
    // ll A[] = {1, 2, 3, 4, 5};
    quickSort(0, sizeof(A) / sizeof(ll) - 1, A);
    //Print
    For(i, 0, sizeof(A) / sizeof(ll), 1)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}