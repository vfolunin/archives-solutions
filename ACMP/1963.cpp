#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> read() {
    vector<vector<int>> a;
    for (string s; cin >> s; ) {
        a.emplace_back(vector<int>(1));
        for (char c : s) {
            if (c == ';')
                a.back().emplace_back();
            else
                a.back().back() = a.back().back() * 10 + c - '0';
        }
    }
    return a;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> a = read();
    reverse(a.begin(), a.end());
    
    vector<vector<int>> minRes(a.size(), vector<int>(a[0].size(), 1e9));
    vector<vector<int>> maxRes(a.size(), vector<int>(a[0].size(), -1e9));
    minRes[0][0] = maxRes[0][0] = a[0][0];

    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a[0].size(); x++) {
            if (y) {
                minRes[y][x] = min(minRes[y][x], minRes[y - 1][x] + abs(a[y - 1][x] - a[y][x]));
                maxRes[y][x] = max(maxRes[y][x], maxRes[y - 1][x] + abs(a[y - 1][x] - a[y][x]));
            }
            if (x) {
                minRes[y][x] = min(minRes[y][x], minRes[y][x - 1] + abs(a[y][x - 1] - a[y][x]));
                maxRes[y][x] = max(maxRes[y][x], maxRes[y][x - 1] + abs(a[y][x - 1] - a[y][x]));
            }
        }
    }

    cout << minRes.back().back() << " " << maxRes.back().back();
}