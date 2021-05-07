#include <iostream>
#include <ctime>
using namespace std;

typedef long long int ll;

int main()
{
    ll n;
    cin >> n;
    time_t start, end;

    start = clock();

    ll fibonacci[n];
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (ll i = 2; i < n; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    for (ll j = 0; j < n; j++)
        cout << fibonacci[j] << "   ";
    cout << endl;

    end = clock();

    cout << "Time Taken : " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    return 0;
}

// effective way : f(n) = 1/sqrt(5)(((1+sqrt(5))/2)^n - ((1-sqrt(5))/2)^n)