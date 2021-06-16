#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<int, vector<vector<int>>> getSubsets(int n, int l, int r) {
    map<int, vector<vector<int>>> res;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        for (int bit = 0; bit < n; bit++)
            if (mask & (1 << bit))
                subset.push_back(bit);

        if (l <= subset.size() && subset.size() <= r)
            res[subset.size()].push_back(subset);
    }
    for (auto &[_, subsets] : res)
        sort(subsets.begin(), subsets.end());
    return res;
}

void solve(int test) {
    string line;
    getline(cin, line);

    int l, r;
    if (line == "*") {
        l = 1;
        r = 12;
    } else {
        stringstream ss(line);
        ss >> l;
        if (!(ss >> r))
            r = l;
    }

    vector<string> names;
    while (getline(cin, line) && !line.empty())
        names.push_back(line);

    if (test)
        cout << "\n";
    map<int, vector<vector<int>>> subsets = getSubsets(names.size(), l, r);
    for (auto &[size, subsets] : subsets) {
        cout << "Size " << size << "\n";
        for (auto &subset : subsets)
            for (int i = 0; i < subset.size(); i++)
                cout << names[subset[i]] << (i + 1 < subset.size() ? ", " : "\n");
        cout << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}