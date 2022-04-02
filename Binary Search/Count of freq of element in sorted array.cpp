// Author : Deepdarshan
// Count the freq of target in sorted array

#include <bits/stdc++.h>
using namespace std;

int freqCount(vector<int> arr, int target) {
    auto low = lower_bound(arr.begin(), arr.end(), target);
    auto high = upper_bound(arr.begin(), arr.end(), target);
    int count = high - low;
    return count;
}

int main() {
    vector<int> arr{2, 4, 10, 10, 10, 18, 20};

    cout << freqCount(arr, 10) << endl;
    cout << freqCount(arr, 6) << endl;

    return 0;
}