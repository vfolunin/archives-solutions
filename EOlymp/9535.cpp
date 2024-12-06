#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n, w, w2;
    string s;
    cin >> n >> w >> w2 >> s;

    int cw = 0, res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cw++;
            if (cw == w) {
                res++;
                fill(s.begin() + i, min(s.end(), s.begin() + i + w2), '1');
                cw = 0;
            }
        } else {
            cw = 0;
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 1;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        solve();
}