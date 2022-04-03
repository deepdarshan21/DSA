// Author : Deepdarshan
// Find ceil of target in sorted array(ceil mean smallest element greater than equal to given number)

#include <bits/stdc++.h>
using namespace std;

int ceil(vector<int> arr, int target) {
    int low = 0, mid, high = arr.size() - 1;
    int ceil = -1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (target == arr[mid]) {
            ceil = arr[mid];
            break;
        } else {
            if (target < arr[mid]) {
                ceil = arr[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return ceil;
}

int main() {
    vector<int> arr{1, 2, 3, 4, 8, 10, 10, 12};

    cout << ceil(arr, 5) << endl;
    cout << ceil(arr, 10) << endl;

    return 0;
}