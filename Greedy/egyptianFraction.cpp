#include <bits/stdc++.h>
using namespace std;
#define For(i, a, n, k) for (int i = a; i < n; i += k)

int main()
{
    int nr, dr;
    cin >> nr >> dr;
    vector<int> ans;
    float n1;
    n1 = (float)nr / dr;
    cout << nr << "/" << dr << " can be represented by sum of ";
    int t = 2;
    while (true)
    {
        if ((float)nr / dr == 0)
            break;
        else
        {
            int n2 = ceil((float)dr / nr);
            ans.push_back(n2);
            n1 = n1 - (float)1 / n2;
            dr = dr * n2;
            nr = (nr * n2) - dr / n2;
        }
        }
    for (auto i : ans)
    {
        cout << "1/" << i << " + ";
    }
    cout << endl;
}