// Author: Deepdarshan
// https://www.geeksforgeeks.org/allocate-minimum-number-pages/

#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(nlog(n)) Space Complexity: O(1)
*/

bool isValid(vector<int> arr, int key, int mid) {
    int sum = 0;
    int count = 1;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (sum > mid) {
            count++;
            sum = arr[i];
        }
        if (count > key) {
            return false;
        }
    }
    return true;
}

int binarySearch(vector<int> arr, int key) {
    int low = *max_element(arr.begin(), arr.end()), mid, high = accumulate(arr.begin(), arr.end(), 0);
    int minPages;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (isValid(arr, key, mid)) {
            minPages = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return minPages;
}

int main() {
    vector<int> arr{10, 20, 30, 40};

    cout << binarySearch(arr, 2) << endl;
    cout << binarySearch(arr, 3) << endl;

    return 0;
}