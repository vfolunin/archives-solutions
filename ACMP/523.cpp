#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> a, int partLimit, int sumLimit) {
    int sum = 0, parts = 1;
    for (int value : a) {
        if (sum + value <= sumLimit) {
            sum += value;
        } else {
            sum = value;
            parts++;
        }
    }
    return parts <= partLimit;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int partLimit;
    cin >> partLimit;

    int l = *max_element(a.begin(), a.end()) - 1, r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(a, partLimit, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}