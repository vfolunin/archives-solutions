#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool lessOrEqual(string &a, string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a <= b;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    int canUseB;
    cin >> s >> canUseB;

    string res;
    for (char a = '0'; a <= '9'; a++) {
        for (int size = s.size(); size <= s.size() + 1; size++) {
            string cur(size, a);

            if (canUseB) {
                for (char b = '0'; b <= '9'; b++) {
                    for (int pos = 0; pos < cur.size(); pos++) {
                        cur[pos] = b;

                        if (lessOrEqual(s, cur) && (res.empty() || lessOrEqual(cur, res)))
                            res = cur;

                        cur[pos] = a;
                    }
                }
            } else {
                if (lessOrEqual(s, cur) && (res.empty() || lessOrEqual(cur, res)))
                    res = cur;
            }
        }
    }

    cout << res;
}