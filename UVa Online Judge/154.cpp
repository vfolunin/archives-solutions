#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int diff(const map<char, char> &a, const map<char, char> &b) {
    int res = 0;
    for (const auto &[key, val] : a)
        res += val != b.at(key);
    return res;
}

int diff(const map<char, char> &a, const vector<map<char, char>> &maps) {
    int res = 0;
    for (const auto &b : maps)
        res += diff(a, b);
    return res;
}

bool solve() {
    vector<map<char, char>> maps;
    while (1) {
        string line;
        cin >> line;

        if (line == "#")
            return 0;

        if (line[0] == 'e')
            break;

        maps.emplace_back();
        for (int i = 0; i < line.size(); i += 4)
            maps.back()[line[i]] = line[i + 2];
    }

    int res = -1, resDiff = 1e9;
    for (int i = 0; i < maps.size(); i++) {
        int curDiff = diff(maps[i], maps);
        if (curDiff < resDiff) {
            resDiff = curDiff;
            res = i;
        }
    }

    cout << res + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}