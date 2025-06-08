#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("cube.in", "r", stdin);
    freopen("cube.out", "w", stdout);

    string s;
    cin >> s;

    sort(s.begin(), s.end());
    do {
        if (s[0] != s[1] && s[0] != s[2] && s[0] != s[4] && s[1] != s[3] &&
            s[1] != s[5] && s[2] != s[3] && s[2] != s[6] && s[3] != s[7] &&
            s[4] != s[5] && s[4] != s[6] && s[5] != s[7] && s[6] != s[7]) {
            cout << 1;
            return 0;
        }
    } while (next_permutation(s.begin(), s.end()));

    cout << 0;
}