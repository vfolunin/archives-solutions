#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int operator % (const string &s, int n) {
    int res = 0;
    for (char c : s)
        res = (res * 10 + c - '0') % n;
    return res;
}

void solve() {
    string s;
    int divisorCount;
    cin >> s >> divisorCount;

    bool isWonderful = 1;
    for (int i = 0; i < divisorCount; i++) {
        int divisor;
        cin >> divisor;
        isWonderful &= s % divisor == 0;
    }

    cout << s << " - " << (isWonderful ? "Wonderful" : "Simple") << ".\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}