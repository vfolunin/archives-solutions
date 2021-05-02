#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toString2(int n) {
    string res = to_string(n);
    if (res.size() == 1)
        res = "0" + res;
    return res;
}

bool solve() {
    string a, b;
    if (!(cin >> a >> b))
        return 0;

    vector<vector<int>> edit(a.size() + 1, vector<int>(b.size() + 1));
    vector<vector<pair<string, int>>> op(a.size() + 1, vector<pair<string, int>>(b.size() + 1));

    for (int ka = 1; ka <= a.size(); ka++) {
        edit[ka][0] = ka;
        op[ka][0] = { "D" + string(1, a[ka - 1]), ka };
    }

    for (int kb = 1; kb <= b.size(); kb++) {
        edit[0][kb] = kb;
        op[0][kb] = { "I" + string(1, b[kb - 1]), kb };
    }

    for (int ka = 1; ka <= a.size(); ka++) {
        for (int kb = 1; kb <= b.size(); kb++) {
            if (a[ka - 1] == b[kb - 1]) {
                edit[ka][kb] = edit[ka - 1][kb - 1];
                op[ka][kb] = { "-", 0 };
            } else {
                edit[ka][kb] = edit[ka - 1][kb - 1] + 1;
                op[ka][kb] = { "C" + string(1, b[kb - 1]), ka };

                if (edit[ka][kb] > edit[ka - 1][kb] + 1) {
                    edit[ka][kb] = edit[ka - 1][kb] + 1;
                    op[ka][kb] = { "D" + string(1, a[ka - 1]), ka };
                }

                if (edit[ka][kb] > edit[ka][kb - 1] + 1) {
                    edit[ka][kb] = edit[ka][kb - 1] + 1;
                    op[ka][kb] = { "I" + string(1, b[kb - 1]), kb };
                }
            }
        }
    }

    vector<pair<string, int>> ops;
    for (int ka = a.size(), kb = b.size(); ka || kb; ) {
        ops.push_back(op[ka][kb]);
        if (op[ka][kb].first[0] == 'D') {
            ka--;
        } else if (op[ka][kb].first[0] == 'I') {
            kb--;
        } else {
            ka--;
            kb--;
        }
    }

    reverse(ops.begin(), ops.end());
    int shift = 0;
    for (auto &[op, i] : ops) {
        if (op != "-")
            cout << op << toString2(i + shift * (op[0] != 'I'));
        shift += op[0] == 'I';
        shift -= op[0] == 'D';
    }
    cout << "E\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}