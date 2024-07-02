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
    int limit;
    cin >> s >> limit;

    vector<int> mismatch(s.size());
    for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
        if (s[l] != s[r]) {
            mismatch[l] = mismatch[r] = 1;
            limit--;
        }
    }

    if (limit < 0) {
        cout << ":(";
        return 0;
    }

    for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
        if (mismatch[l]) {
            if (s[l] != 'z' && s[r] != 'z' && limit) {
                s[l] = s[r] = 'z';
                limit--;
            } else {
                s[l] = s[r] = max(s[l], s[r]);
            }
        } else if (s[l] != 'z' && limit >= 2) {
            s[l] = s[r] = 'z';
            limit -= 2;
        }
    }

    if (s.size() % 2 && limit)
        s[s.size() / 2] = 'z';

    cout << s;
}