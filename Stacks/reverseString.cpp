// Author : Deepdarshan
//Program for reversing of a String using Character Array

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

class Stack
{
private:
    char ch[101];
    int top = -1;

public:
    void push(char x)
    {
        top += 1;
        ch[top] = x;
    }
    void pop()
    {
        top -= 1;
    }
    char Top()
    {
        return ch[top];
    }
    bool isEmpty()
    {
        if (top >= 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

char *reverse(char *S, int len)
{
    Stack s;
    For(i, 0, len, 1)
    {
        s.push(S[i]);
    }
    int i = 0;
    while (s.isEmpty() == false)
    {
        S[i] = s.Top();
        ++i;
        s.pop();
    }
}

int main()
{
    cout << "ENTER THE STRING THAT YOU WANT TO REVERSE: ";
    char C[101];
    gets(C);
    reverse(C, strlen(C));
    cout << "Output = " << C << endl;
    char ch = getch();
    return 0;
}