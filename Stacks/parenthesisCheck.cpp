// Author : Deepdarshan
//Program for Parenthesis Check

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

bool checkParenthesis(string S, int len)
{
    stack<char> C;
    For(i, 0, len, 1)
    {
        if (S[i] == '(')
            C.push(')');
        else if (S[i] == '{')
            C.push('}');
        else if (S[i] == '[')
            C.push(']');
        else if (S[i] == ')' || S[i] == '}' || S[i] == ']')
        {
            if (C.empty())
            {
                return false;
            }
            else
            {
                if (C.top() == S[i])
                    C.pop();
                else
                    return false;
            }
        }
    }
    return C.empty();
}

int main()
{
    cout << "ENTER THE STRING ON WHICH YOU WANT TO CHECK: ";
    string S;
    getline(cin, S);
    bool ans = checkParenthesis(S, S.length());
    if (ans)
    {
        cout << "VALID" << endl;
    }
    else
    {
        cout << "NOT VALID" << endl;
    }
    char ch = getch();
    return 0;
}
