/*
    Given n number of sorted files, the task is to find the minimum computations done to reach the Optimal Merge Pattern
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    int ans = 0;
    while (pq.size() > 1)
    {
        int a1 = pq.top();
        pq.pop();
        int a2 = pq.top();
        pq.pop();
        ans += a1 + a2;
        pq.push(a1 + a2);
    }
    cout << ans << endl;
    return 0;
}