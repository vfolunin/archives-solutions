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
    cin >> s >> s;

    vector<vector<int>> ops(s.size(), vector<int>(2));
    ops[0] = { s[0] != 'A', s[0] != 'B' };

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'A') {
            ops[i][0] = ops[i - 1][0];
            ops[i][1] = min(ops[i - 1][0], ops[i - 1][1]) + 1;
        } else {
            ops[i][0] = min(ops[i - 1][0], ops[i - 1][1]) + 1;
            ops[i][1] = ops[i - 1][1];
        }
    }

    cout << ops.back()[0];
}