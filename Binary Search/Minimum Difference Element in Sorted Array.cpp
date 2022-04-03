// Author: Deepdarshan
// Find the element who has minimum difference with target element

#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(log(n)) Space Complexity: O(1)
*/

int minDiffElementApproach1(vector<int> arr, int target) {
    int low = 0, mid, high = arr.size() - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if ((arr[mid] <= target) && (mid == (arr.size() - 1) || arr[mid + 1] >= target)) {
            int minDiff, res;
            minDiff = abs(target - arr[mid]);
            res = arr[mid];
            if (mid < (arr.size() - 1)) {
                if (minDiff > abs(target - arr[mid + 1])) {
                    res = arr[mid + 1];
                }
            }
            return res;

        } else {
            if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return arr[0];
}

int minDiffElementApproach2(vector<int> arr, int target) {
    int low = 0, mid, high = arr.size() - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return arr[mid];
        } else {
            if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return abs(target - arr[low]) < abs(target - arr[high]) ? arr[low] : arr[high];
}

int main() {
    vector<int> arr{1, 3, 8, 10, 15};

    cout << "By Approach 1" << endl;
    cout << minDiffElementApproach1(arr, 12) << endl;
    cout << minDiffElementApproach1(arr, 14) << endl;
    cout << minDiffElementApproach1(arr, 19) << endl;
    cout << minDiffElementApproach1(arr, 4) << endl;
    cout << minDiffElementApproach1(arr, -2) << endl;

    cout << "By Approach 2" << endl;
    cout << minDiffElementApproach2(arr, 12) << endl;
    cout << minDiffElementApproach2(arr, 14) << endl;
    cout << minDiffElementApproach2(arr, 19) << endl;
    cout << minDiffElementApproach2(arr, 4) << endl;
    cout << minDiffElementApproach2(arr, -2) << endl;

    return 0;
}