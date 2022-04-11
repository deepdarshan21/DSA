// Author : Deepdarshan
// Find how many times array is rotated(left to right)

#include <bits/stdc++.h>
using namespace std;

int numberOfTimesRotated(vector<int> arr) {
    // need to find pos of min element in arr => ans: (size of arr-pos)%6
    int low = 0, mid, high = arr.size() - 1;
    int midPos;
    while (low <= high) {
        mid = low + (high - low) / 2;
        cout << low << " " << mid << " " << high << endl;
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
    cout << midPos << endl;
    return (arr.size() - midPos) % arr.size();
}

int findMin(vector<int>& nums) {
    int low = 0, mid, high = nums.size() - 1;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            // for duplicates
            low++;
            high--;
        } else {
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
    }
    return nums[low];
}

int main() {
    vector<int> arr{10, 11, 12, 13, 14, 15, 7, 8, 9};

    cout << numberOfTimesRotated(arr) << endl;

    cout << findMin(arr) << endl;

    return 0;
}