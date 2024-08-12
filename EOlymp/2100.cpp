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

    int size;
    cin >> size;

    vector<pair<int, int>> res;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (res.empty() || res.back().second + 1 < value)
            res.push_back({ value, value });
        else
            res.back().second++;
    }

    bool first = 1;
    for (auto &[l, r] : res) {
        if (first)
            first = 0;
        else
            cout << ",";

        cout << l;
        if (l < r)
            cout << "-" << r;
    }
}