#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> zFunction(const string &s) {
    vector<int> z(s.size());

    int blockL = 0, blockR = 0;
    for (int i = 1; i < s.size(); i++) {
        int blockLen = 0;

        if (i <= blockR)
            blockLen = min(z[i - blockL], blockR - i + 1);

        while (i + blockLen <= s.size() && s[i + blockLen] == s[blockLen])
            blockLen++;

        z[i] = blockLen;

        if (blockR < i + blockLen - 1) {
            blockL = i;
            blockR = i + blockLen - 1;
        }
    }

    return z;
}

void solve() {
    string s;
    cin >> s;

    vector<int> z = zFunction(s);
    int n = s.size() / 2;
    while (z[n] < n)
        n--;

    for (int i = 0, si = s.size() % n; i < 8; i++, si = (si + 1) % n)
        cout << s[si];
    cout << "...\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}