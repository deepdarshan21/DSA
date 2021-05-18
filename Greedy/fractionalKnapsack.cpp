/* 
    Given weights and values of n items, we need to put it these items in knapsack of capacity W to get the
    maximum total value in knapsack
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    int w;
    cin >> w;
    sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b)
         {
             float c = (float)a.first / a.second;
             float d = (float)b.first / b.second;
             return c > d;
         });
    int ans = 0, i = 0;
    // cout << "here" << endl;
    while (w != 0)
    {
        if (w - v[i].second > 0)
        {
            ans += v[i].first;
            w -= v[i].second;
        }
        else
        {
            ans += (v[i].first / v[i].second) * (w);
            w = 0;
        }
        ++i;
    }
    cout << ans << endl;
    return 0;
}