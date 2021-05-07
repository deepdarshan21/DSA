#include <bits/stdc++.h>
using namespace std;
int fact(int *a, int n)
{
    if (n == 1)
        return a[0];
    else
        return a[n - 1] * fact(a, n - 1);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int ans = fact(a, n);
    cout << ans;
    return 0;
}
