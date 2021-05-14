// Author : Deepdarshan
//Program of stack using arrays
//It follows LIFO(Last In First Out)

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

void push(ll *S, ll x)
{
    ll i = 0;
    while (1)
    {
        if (S[i] == 0)
        {
            break;
        }
        ++i;
    }
    S[i] = x;
}

void pop(ll *S)
{
    ll i = 0;
    while (1)
    {
        if (S[i] == 0)
        {
            break;
        }
        ++i;
    }
    S[i - 1] = 0;
}

void top(ll *S)
{
    ll i = 0;
    while (1)
    {
        if (S[i] == 0)
        {
            break;
        }
        ++i;
    }
    cout << "Top Element " << S[i - 1] << endl;
}

void isEmpty(ll *S)
{
    if (S[0] == 0)
    {
        cout << "YES IT IS EMPTY" << endl;
    }
    else
    {
        cout << "NO IT IS NOT EMPTY" << endl;
    }
}
void print(ll *S)
{
    ll i = 0;
    while (1)
    {
        if (S[i] == 0)
        {
            break;
        }
        cout << S[i] << "  ";
        ++i;
    }
    cout << endl;
}

int main()
{
    cout << "PROGRAM FOR STACK OPERATIONS USING ARRAY" << endl;
    ll S[1000];
    memset(S, 0, sizeof(S) / sizeof(ll));
    cout << endl
         << "AVAILABLE OPERATIONS:" << endl
         << "1. Push" << endl
         << "2. Pop" << endl
         << "3. Top" << endl
         << "4. isEmpty" << endl
         << "5. Print" << endl
         << "6. Exit" << endl;
    ll size = 0;
    string input;
    while (size < 1000)
    {
        cout << "Enter Operation Name: " << endl;
        cin >> input;
        if (input.compare("Push") == 0)
        {
            ll pushInput;
            cout << "     Enter the number: ";
            cin >> pushInput;
            if (size < 999)
            {
                push(S, pushInput);
            }
            size += 1;
        }
        else if (input.compare("Pop") == 0)
        {
            pop(S);
            size -= 1;
        }
        else if (input.compare("Top") == 0)
        {
            top(S);
        }
        else if (input.compare("isEmpty") == 0)
        {
            isEmpty(S);
        }
        else if (input.compare("Print") == 0)
        {
            print(S);
        }
        else if (input.compare("Exit") == 0)
        {
            break;
        }
        else
        {
            cout << "Invalid Choice!" << endl;
        }
    }
    if (size == 1000)
    {
        cout << "SIZE OVERFLOWED!" << endl;
        print(S);
    }
    char ch = getch();
    return 0;
}