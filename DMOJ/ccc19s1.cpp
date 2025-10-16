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

    string s;
    cin >> s;

    int h = 0, v = 0;
    for (char c : s) {
        h ^= c == 'H';
        v ^= c == 'V';
    }

    vector<vector<int>> res = { { 1, 2 }, { 3, 4 } };
    if (h)
        swap(res[0], res[1]);
    if (v) {
        swap(res[0][0], res[0][1]);
        swap(res[1][0], res[1][1]);
    }

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
}