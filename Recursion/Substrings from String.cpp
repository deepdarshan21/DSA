#include <bits/stdc++.h>
using namespace std;

void recursion(string given, string formedTillNow, int pos) {
    cout << formedTillNow << "😉" << endl;
    while (pos < given.size()) {
        recursion(given, formedTillNow + given[pos], pos + 1);
        pos++;
    }
}

int main() {
    string givenString = "abc";
    recursion(givenString, "", 0);
    return 0;
}