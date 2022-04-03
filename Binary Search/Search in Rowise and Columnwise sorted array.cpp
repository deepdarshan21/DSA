// Author: Deepdarshan
// Find the target element in rowise and columnwise sorted array

#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(log(n)) Space Complexity: O(1)
*/

bool binarySearch(vector<vector<int>> arr, int target) {
    int i = 0, j = arr[0].size() - 1;
    while (i < arr.size() && j >= 0) {
        if (arr[i][j] == target) {
            return true;
        } else {
            if (arr[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> arr{
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 43},
        {32, 33, 39, 50}};

    cout << (bool)binarySearch(arr, 29) << endl;
    cout << (bool)binarySearch(arr, 50) << endl;
    cout << (bool)binarySearch(arr, 24) << endl;

    return 0;
}