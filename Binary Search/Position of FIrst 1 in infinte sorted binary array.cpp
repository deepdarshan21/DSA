// Author: Deepdarshan
// Find the index of first 1 in binary sorted array

#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(log(n)) Space Complexity: O(1)
*/

int indexOfFirst1(vector<int> arr) {
    int low = 0, mid, high = 1;
    // find the subarray where target element is lying
    while (arr[high] == 0) {
        low = high;
        high *= 2;
    }
    cout << arr[high] << endl;
    cout << low << " " << high << endl;

    // apply normal BS on subarray where target is lying
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == 1 && (mid == low || arr[mid - 1] == 0)) {
            return mid;
        } else {
            if (arr[mid] == 1) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr{
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
    };

    cout << indexOfFirst1(arr) << endl;

    return 0;
}