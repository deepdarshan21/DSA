// Author : Deepdarshan
// Binary Search Implementation

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int target) {
    int low = 0, mid, high = arr.size() - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        cout << low << " " << mid << " " << high << endl;
        if (arr[mid] == target) {
            return mid;
        } else {
            if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr{3, 5, 6, 9, 11, 14, 16};

    cout << binarySearch(arr, 14) << endl;

    cout << binarySearch(arr, 1) << endl;

    return 0;
}