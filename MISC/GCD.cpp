#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
    {
        /* cout << "gcd(" << a << ", " << b << ")"
             << " -> "; */
        a %= b;
        gcd(b, a);
        /* cout << "gcd(" << b << ", " << a << ")"
             << " -> "; */
    }
}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll ans;
    if (a > b)
        ans = gcd(a, b);
    else if (a < b)
        ans = gcd(b, a);
    else
        ans = a;
    cout << ans << endl;
    return 0;
}