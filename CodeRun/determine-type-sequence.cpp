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

    vector<int> a;

    while (1) {
        int value;
        cin >> value;

        if (value == -2e9)
            break;

        a.push_back(value);
    }

    bool constant = 1, ascending = 1, weaklyAscending = 1, descending = 1, weaklyDescending = 1;
    for (int i = 1; i < a.size(); i++) {
        constant &= a[i - 1] == a[i];
        ascending &= a[i - 1] < a[i];
        weaklyAscending &= a[i - 1] <= a[i];
        descending &= a[i - 1] > a[i];
        weaklyDescending &= a[i - 1] >= a[i];
    }

    if (constant)
        cout << "CONSTANT";
    else if (ascending)
        cout << "ASCENDING";
    else if (weaklyAscending)
        cout << "WEAKLY ASCENDING";
    else if (descending)
        cout << "DESCENDING";
    else if (weaklyDescending)
        cout << "WEAKLY DESCENDING";
    else
        cout << "RANDOM";
}