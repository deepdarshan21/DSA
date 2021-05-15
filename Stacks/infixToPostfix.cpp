// Program for converting a infix experation to postfix

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
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

string infixToPostfix(string infix, int size)
{
    // stringstream convertInt(infix);
    stringstream convertString(infix);
    // int x1;
    char x1 = ')', x2;
    stack<char> S;
    string ans = "";

    while (convertString >> x2)
    {
        if (!(x2 == '+' || x2 == '-' || x2 == '*' || x2 == '/' || x2 == '(' || x2 == ')'))
        {
            ans += x2;
            ans += " ";
        }
        else
        {
            if (x1 == '(' && x2 != ')')
            {
                S.push(x2);
            }
            else if (x2 == '(')
            {
                S.push('(');
                x1 = '(';
            }
            else if (x2 == ')')
            {
                while (S.top() != '(')
                {
                    ans += S.top();
                    ans += " ";
                    S.pop();
                }
                S.pop();
                x1 = ')';
            }
            else if (x2 == '*' || x2 == '/')
            {
                if (S.empty() || S.top() == '+' || S.top() == '-')
                {
                    S.push(x2);
                }
                else
                {
                    ans += S.top();
                    ans += " ";
                    S.pop();
                    S.push(x2);
                }
            }
            else if (x2 == '+' || x2 == '-')
            {
                if (S.empty())
                {
                    S.push(x2);
                }
                else if (S.top() == '*' || S.top() == '/')
                {
                    ans += S.top();
                    ans += " ";
                    S.pop();
                    while (!S.empty())
                    {
                        ans += S.top();
                        ans += " ";
                        S.pop();
                    }
                    S.push(x2);
                }
                else
                {
                    ans += S.top();
                    ans += " ";
                    S.pop();
                    S.push(x2);
                }
            }
        }
    }
    while (!S.empty())
    {
        ans += S.top();
        ans += " ";
        S.pop();
    }

    return ans;
}

int main()
{
    string s, ans;

    cout << "PROGRAM FOR CONVERSION OF A INFIX OPERATION TO POSTFIX OPERATION" << endl;
    cout << "Inter your infix expresion: ";
    getline(cin, s);

    ans = infixToPostfix(s, s.length());
    cout << "Your converted postfix operation is: " << ans << endl;

    char ch = getch();
    return 0;
}