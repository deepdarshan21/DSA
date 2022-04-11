// Author: Deepdarshan
// https://www.geeksforgeeks.org/allocate-minimum-number-pages/

#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(log(n)) Space Complexity: O(1)
    Remarks: binary search on answer.
    Indentify the correct position by dividing both array into two parts and comparing
    left1(max element) with right2(min element) and left2(max element) with right1(min element)
*/

double findMedian(vector<int> arr1, vector<int> arr2) {
    if (arr1.size() > arr2.size()) {
        return findMedian(arr2, arr1);
    }

    int n1, n2, low, high, cut1, cut2, l1, l2, h1, h2;
    double median;
    n1 = arr1.size();
    n2 = arr2.size();

    low = 0;
    high = n1;
    while (low <= high) {
        cut1 = low + (high - low) / 2;
        cut2 = ((n1 + n2 + 1) / 2) - cut1;

        l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        h1 = cut1 == n1 ? INT_MAX : arr1[cut1];
        h2 = cut2 == n2 ? INT_MAX : arr2[cut2];

        if (l1 <= h2 && l2 <= h1) {
            if ((n1 + n2) % 2 == 0) {
                median = (max(l1, l2) + min(h1, h2)) / 2.0;
            } else {
                median = (max(l1, l2) / 1.0);
            }
            break;
        } else {
            if (l1 > h2) {
                high = cut1 - 1;
            } else if (l2 > h1) {
                low = cut1 + 1;
            }
        }
    }
    return median;
}

int main() {
    vector<int> arr1{1, 2, 3, 4, 9, 11}, arr2{7, 12, 14, 15};

    cout << findMedian(arr1, arr2) << endl;

    return 0;
}