#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    cin >> queryCount;

    int l = 0, r = 10;
    for (int i = 0; i < queryCount; i++) {
        int value;
        string status;
        cin >> value >> status;

        if (status == "hungry")
            l = max(l, value);
        else
            r = min(r, value);
    }

    if (l < r)
        cout << r;
    else
        cout << "Inconsistent";
}