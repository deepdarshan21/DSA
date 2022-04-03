// Author : Deepdarshan
// Find floor of target in sorted array(floor mean greatest element smaller than equal to target)

#include <bits/stdc++.h>
using namespace std;

int floor(vector<int> arr, int target) {
    int low = 0, mid, high = arr.size() - 1;
    int floor = -1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (target == arr[mid]) {
            floor = arr[mid];
            break;
        } else {
            if (target < arr[mid]) {
                high = mid - 1;
            } else {
                floor = arr[mid];
                low = mid + 1;
            }
        }
    }
    return floor;
}

int main() {
    vector<int> arr{1, 2, 3, 4, 8, 10, 10, 12};

    cout << floor(arr, 5) << endl;
    cout << floor(arr, 10) << endl;

    return 0;
}