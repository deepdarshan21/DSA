// Program for evaluating a given postfix experation
// In postfix experation operand are on left and operator on right
// Works only for single digit positive intigers

#include <iostream>
#include <conio.h>
#include <string>
#include <stack>
using namespace std;
typedef long long int ll;
#define For(i, a, n, k) for (ll i = a; i < n; i += k)
#define SWAP(a, b) \
    {              \
        a = a + b; \
        b = a - b; \
        a = a - b; \
    }

int evaluatePostfix(string s, int size)
{
    stack<int> S;
    int op1, op2, result;

    For(i, 0, size, 2)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            S.push(int(s[i]) - int('0'));
        }
        else
        {
            op2 = S.top();
            S.pop();
            op1 = S.top();
            S.pop();
            if (s[i] == '+')
            {
                result = op1 + op2;
                S.push(result);
            }
            else if (s[i] == '-')
            {
                result = op1 - op2;
                S.push(result);
            }
            else if (s[i] == '*')
            {
                result = op1 * op2;
                S.push(result);
            }
            else if (s[i] == '/')
            {
                result = op1 / op2;
                S.push(result);
            }
        }
    }
    return (S.top());
}

int main()
{
    string s;
    int size, ans;

    cout << "PROGRAM FOR EVALUATING A POSTIX EXPERATION" << endl;
    cout << "Enter your postfix operation: ";
    getline(cin, s);

    ans = evaluatePostfix(s, s.length());
    cout << "After evaluation answer = " << ans << endl;

    char ch = getch();
    return 0;
}