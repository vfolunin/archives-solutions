#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<vector<int>> &a, int limit) {
    for (vector<int> &a : a) {
        int last = 0;
        for (int value : a) {
            if (value <= limit)
                continue;
            if (last == 0)
                last = value;
            else if (last == value)
                last = 0;
            else
                return 0;
        }
        if (last)
            return 0;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> a(2, vector<int>(size));
    for (vector<int> &a : a)
        for (int &value : a)
            cin >> value;

    int l = -1, r = 1;
    while (!can(a, r))
        r *= 2;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(a, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}