#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> read() {
    string s;
    getline(cin, s);
    vector<int> v(26);
    for (char c : s)
        v[c - 'A'] = 1;
    return v;
}

void solve() {
    vector<int> a = read();
    vector<int> b = read();
    vector<int> c = read();

    string res;
    for (int i = 0; i < 26; i++) {
        a[i] -= b[i] + c[i];
        if (a[i] < 0) {
            cout << "CHEATER\n";
            return;
        }
        if (a[i])
            res += 'A' + i;
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}