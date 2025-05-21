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
    for (int i = 0; i < s.size(); i++)
        pos[s[i] - 'a'].push_back(i);

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int resCount = 0;
        char res;
        for (int j = 0; j < pos.size(); j++) {
            int count = upper_bound(pos[j].begin(), pos[j].end(), r) -
                        lower_bound(pos[j].begin(), pos[j].end(), l);
            if (resCount < count) {
                resCount = count;
                res = j + 'a';
            }
        }

        cout << res << " " << resCount << "\n";
    }
}