#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, threshold;
    string s;
    cin >> size >> threshold >> s;

    int res = 0;
    for (int i = 0; i < size && i < threshold; i++) {
        if (s[i] == 'L') {
            s[i] = 'R';
            res++;
        }
    }
    for (int i = size - 1; i >= 0 && i >= size - threshold; i--) {
        if (s[i] == 'R') {
            s[i] = 'L';
            res++;
        }
    }

    if (find(s.begin(), s.begin() + threshold, 'L') == s.begin() + threshold &&
        find(s.end() - threshold, s.end(), 'R') == s.end())
        cout << res << "\n";
    else
        cout << "-1\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}