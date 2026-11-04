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
    int queryCount;
    cin >> s >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int sl = 0, sr = count(s.begin() + l, s.begin() + r + 1, 's'), res = 0;
        for (int j = l; j <= r; j++) {
            if (s[j] == 's') {
                sl++;
                sr--;
            } else if (s[j] == 'm') {
                res += sl * sr;
            }
        }

        cout << res << "\n";
    }
}