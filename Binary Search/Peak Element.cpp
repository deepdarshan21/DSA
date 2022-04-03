// Author: Deepdarshan
// Find the peak element in an array

#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(log(n)) Space Complexity: O(1)
*/

int modifiedBSForPeakElement(vector<int> arr) {
    int low = 0, mid, high = arr.size() - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if ((mid == 0 || arr[mid - 1] < arr[mid]) && (mid == (arr.size() - 1) || arr[mid + 1] < arr[mid])) {
            return arr[mid];
        } else {
            if (arr[mid - 1] > arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr{5, 10, 20, 15};

    cout << modifiedBSForPeakElement(arr);

    return 0;
}