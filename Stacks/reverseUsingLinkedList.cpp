// Author : Deepdarshan
//Program for reversing of a String using Linked List

#include <iostream>
#include <string>
#include <stack>
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

string reverse(string s, int n)
{
    stack<char> C;
    for (int i = 0; i < n; ++i)
    {
        C.push(s[i]);
    }

    for (int i = 0; i < n; i++)
    {
        s[i] = C.top();
        C.pop();
    }
    return s;
}

int main()
{
    cout << "ENTER THE STRING THAT YOU WANT TO REVERSE: ";
    string S;
    cin >> S;
    S = reverse(S, S.length());
    cout << S << endl;
    char ch = getch();
    return 0;
}