// Author : Deepdarshan
// Find next alphabetical element

#include <bits/stdc++.h>
using namespace std;

int ceil(vector<char> arr, char target) {
    int low = 0, mid, high = arr.size() - 1;
    int nextAlphabetical = 48;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (target < arr[mid]) {
            nextAlphabetical = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return nextAlphabetical;
}

int main() {
    vector<char> arr{'a', 'c', 'f', 'h'};

    cout << (char)ceil(arr, 'e') << endl;
    cout << (char)ceil(arr, 'a') << endl;

    return 0;
}