// Program for insertion sort

#include <iostream>
#include <conio.h>
using namespace std;
typedef long long int ll;
#define For(i, a, n, k) for (ll i = a; i < n; i += k)
#define SWAP(a, b) \
    {              \
        a = a + b; \
        b = a - b; \
        a = a - b; \
    }

void insertionSort(int *arr, int size)
{
    int key;
    For(i, 0, size, 1)
    {
        key = i;
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] > arr[key])
            {
                SWAP(arr[key], arr[j]);
                --key;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    int n, *arr;

    cout << "PRORAM FOR SORTING THE ARRAY USING INSERTION SORT METHOD" << endl;

    cout << "Enter the size of array that you want to sort: ";
    cin >> n;
    arr = new int[n];
    cout << "Now enter the elements of your array: ";
    For(i, 0, n, 1)
    {
        cin >> arr[i];
    }

    insertionSort(arr, n);

    cout << "Increasing order sorted form of your array: ";
    For(i, 0, n, 1)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    char ch = getch();
    return 0;
}