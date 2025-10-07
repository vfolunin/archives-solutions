#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &a, int limit, int boxCount) {
    vector<int> boxes;
    for (int value : a) {
        if (boxes.empty() || boxes.back() + value > limit)
            boxes.push_back(value);
        else
            boxes.back() += value;
    }
    return boxes.size() <= boxCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, boxCount;
    cin >> size >> boxCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int r = *max_element(a.begin(), a.end()), l = r - 1;
    while (!can(a, r, boxCount))
        r *= 2;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(a, m, boxCount))
            r = m;
        else
            l = m;
    }

    cout << r;
}