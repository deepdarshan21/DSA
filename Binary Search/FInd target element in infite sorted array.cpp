// Author: Deepdarshan
// Find index of target in infinte sorted array.cpp

#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(log(n)) Space Complexity: O(1)
*/
int binarySearchOnInfinite(vector<int> arr, int target) {
    int low = 0, mid, high = 1;
    // find the subarray where target element is lying
    while (target >= arr[high]) {
        low = high;
        high *= 2;
        cout << low << " " << high << endl;
    }

    // apply normal BS on subarray where target is lying
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else {
            if (target < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    cout << binarySearchOnInfinite(arr, 10) << endl;
    cout << binarySearchOnInfinite(arr, 5) << endl;
    cout << binarySearchOnInfinite(arr, 14) << endl;
    cout << binarySearchOnInfinite(arr, 18) << endl;

    return 0;
}