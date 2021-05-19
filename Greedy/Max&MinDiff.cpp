#include <bits/stdc++.h>
using namespace std;
#define For(i, a, n, k) for (int i = a; i < n; i += k)

int main()
{
    //main function here
    int n;
    cin >> n;
    vector<int> a(n);
    For(i, 0, n, 1) cin >> a[i];

    sort(a.begin(), a.end());

    int max = 0, min = 0;
    For(i, 0, n / 2, 1)
    {
        max += abs(a[i] - a[n - i - 1]);
    }
    For(i, 0, n, 2)
    {
        min += abs(a[i] - a[i + 1]);
    }

    cout << "Max: " << max << endl
         << "Min: " << min << endl;

    return 0;
}