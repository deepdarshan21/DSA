// Author : Deepdarshan
// Find index of target element in nearly sorted array(nearly sorted mean element that should be present at i can be present at i-1, i, or i+1)

#include <bits/stdc++.h>
using namespace std;

int modifiedBS(vector<int> arr, int target) {
    int low = 0, mid, high = arr.size() - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (mid > low && arr[mid - 1] == target) {
            return mid - 1;
        } else if (arr[mid] == target) {
            return mid;
        } else if (mid < high && arr[mid + 1] == target) {
            return mid + 1;
        } else {
            if (target < arr[mid]) {
                high = mid - 2;
            } else {
                low = mid + 2;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr{20, 10, 40, 30, 50};

    cout << modifiedBS(arr, 20) << endl;
    cout << modifiedBS(arr, 40) << endl;
    cout << modifiedBS(arr, 50) << endl;
    cout << modifiedBS(arr, 0) << endl;

    return 0;
}