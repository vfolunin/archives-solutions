#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string a, b;
    if (!getline(cin, a))
        return 0;
    getline(cin, b);

    vector<vector<int>> edit(a.size() + 1, vector<int>(b.size() + 1));
    vector<vector<string>> op(a.size() + 1, vector<string>(b.size() + 1));

    for (int ka = 1; ka <= a.size(); ka++) {
        edit[ka][0] = ka;
        op[ka][0] = "Delete 1";
    }

    for (int kb = 1; kb <= b.size(); kb++) {
        edit[0][kb] = kb;
        op[0][kb] = "Insert " + to_string(kb) + "," + b[kb - 1];
    }

    for (int ka = 1; ka <= a.size(); ka++) {
        for (int kb = 1; kb <= b.size(); kb++) {
            if (a[ka - 1] == b[kb - 1]) {
                edit[ka][kb] = edit[ka - 1][kb - 1];
                op[ka][kb] = "-";
            } else {
                edit[ka][kb] = edit[ka - 1][kb - 1] + 1;
                op[ka][kb] = "Replace " + to_string(kb) + "," + b[kb - 1];

                if (edit[ka][kb] > edit[ka - 1][kb] + 1) {
                    edit[ka][kb] = edit[ka - 1][kb] + 1;
                    op[ka][kb] = "Delete " + to_string(kb + 1);
                }

                if (edit[ka][kb] > edit[ka][kb - 1] + 1) {
                    edit[ka][kb] = edit[ka][kb - 1] + 1;
                    op[ka][kb] = "Insert " + to_string(kb) + "," + b[kb - 1];
                }
            }
        }
    }

    vector<string> ops;
    for (int ka = a.size(), kb = b.size(); ka || kb; ) {
        if (op[ka][kb] != "-")
            ops.push_back(op[ka][kb]);
        if (op[ka][kb][0] == 'D') {
            ka--;
        } else if (op[ka][kb][0] == 'I') {
            kb--;
        } else {
            ka--;
            kb--;
        }
    }
    reverse(ops.begin(), ops.end());

    if (test)
        cout << "\n";
    cout << ops.size() << "\n";
    for (int i = 0; i < ops.size(); i++)
        cout << i + 1 << " " << ops[i] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}