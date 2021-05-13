/*
   Given n activities with their start and finish times.
   Select the maximum number of activities that can be performed by a single person,
   assuming that a person can only work on a single activity at a time.
*/

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

void modifiedSort(int *arr1, int *arr2, int size)
{
    int key;
    For(i, 0, size, 1)
    {
        key = i;
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr1[j] > arr1[key])
            {
                SWAP(arr1[key], arr1[j]);
                SWAP(arr2[key], arr2[j]);
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
    int act, *start, *end, count, time;
    cout << "PROGRAM FOR \"SELECTION PROGRAM\"" << endl;
    cout << "Number of Activities: ";
    cin >> act;
    start = new int[act];
    end = new int[act];
    cout << "Enter the START time of each activity: ";
    For(i, 0, act, 1)
    {
        cin >> start[i];
    }
    cout << "Enter the END time of each activity: ";
    For(i, 0, act, 1)
    {
        cin >> end[i];
    }

    modifiedSort(end, start, act);
    count = 1;
    time = end[0];
    For(i, 1, act, 1)
    {
        if (time <= start[i])
        {
            time = end[i];
            count += 1;
        }
    }

    cout << "Maximum number of activities the person can do is " << count << endl;

    char ch = getch();
    return 0;
}