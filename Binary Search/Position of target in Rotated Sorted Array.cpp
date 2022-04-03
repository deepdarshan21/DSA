// Author : Deepdarshan
// Find index of target element in rotated sorted array

#include <bits/stdc++.h>
using namespace std;

int posFindApproach1(vector<int> arr, int target) {
    int low = 0, mid, high = arr.size() - 1;
    int midPos;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if ((mid == 0 || arr[mid - 1] > arr[mid]) && (mid == (arr.size() - 1) || arr[mid + 1] > arr[mid])) {
            midPos = mid;
            break;
        } else {
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    int low1 = 0, mid1, high1 = mid - 1;
    while (low1 <= high1) {
        mid1 = low1 + (high1 - low1) / 2;
        if (arr[mid1] == target) {
            return mid1;
        } else {
            if (arr[mid1] > target) {
                high1 = mid1 - 1;
            } else {
                low1 = mid1 + 1;
            }
        }
    }

    int low2 = mid, mid2, high2 = arr.size() - 1;
    while (low2 <= high2) {
        mid2 = low2 + (high2 - low2) / 2;
        if (arr[mid2] == target) {
            return mid2;
        } else {
            if (arr[mid2] > target) {
                high2 = mid2 - 1;
            } else {
                low2 = mid2 + 1;
            }
        }
    }
    return -1;
}

int posFindApproach2(vector<int> arr, int target) {
    int low = 0, mid, high = arr.size() - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else {
            if (arr[mid] < arr[high]) {
                if (target > arr[mid] && target < arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if (target >= arr[low] && target < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr{10, 11, 12, 13, 14, 15, 7, 8, 9};

    cout << "Approach 1" << endl;
    cout << posFindApproach1(arr, 11) << endl;
    cout << posFindApproach1(arr, 8) << endl;
    cout << posFindApproach1(arr, 15) << endl;
    cout << posFindApproach1(arr, 19) << endl;

    cout << "Approach 2" << endl;
    cout << posFindApproach2(arr, 11) << endl;
    cout << posFindApproach2(arr, 8) << endl;
    cout << posFindApproach2(arr, 15) << endl;
    cout << posFindApproach2(arr, 19) << endl;

    return 0;
}