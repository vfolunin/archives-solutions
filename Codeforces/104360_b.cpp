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
 
    int size, queryCount;
    string s;
    cin >> size >> queryCount >> s;

    vector<vector<int>> pos(26);
    for (int i = 0; i < size; i++)
        pos[s[i] - 'a'].push_back(i);

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int res = 0;
        for (int j = 0; j < 26; j++) {
            auto p = lower_bound(pos[j].begin(), pos[j].end(), l);
            auto q = upper_bound(pos[j].begin(), pos[j].end(), r);
            res += (q - p) * (j + 1);
        }

        cout << res << "\n";
    }
}