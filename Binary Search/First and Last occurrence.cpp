// Author : Deepdarshan
// Find first and last occurence of element in sorted array.

#include <bits/stdc++.h>
using namespace std;

int firstOccurBinarySearch(vector<int> arr, int target) {
    int low = 0, mid, high = arr.size() - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        // cout << low << " " << mid << " " << high << endl;
        if (arr[mid] == target && (mid == 0 || (mid > 0 && arr[mid - 1] != target))) {
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

int lastOccurBinarySearch(vector<int> arr, int target) {
    int low = 0, mid, high = arr.size() - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        // cout << low << " " << mid << " " << high << endl;
        if (arr[mid] == target && (mid == arr.size() - 1 || (mid < arr.size() - 1 && arr[mid + 1] != target))) {
            return mid;
        } else {
            if (arr[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr{2, 4, 10, 10, 10, 18, 20};

    cout << firstOccurBinarySearch(arr, 14) << endl;
    cout << firstOccurBinarySearch(arr, 10) << endl;

    cout << lastOccurBinarySearch(arr, 14) << endl;
    cout << lastOccurBinarySearch(arr, 10) << endl;

    return 0;
}