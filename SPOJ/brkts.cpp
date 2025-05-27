#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int balance = 0;
    for (char c : s) {
        balance += c == '{' ? 1 : -1;
        if (balance < 0) {
            cout << ":(\n";
            return;
        }
    }

    cout << (balance ? ":(\n" : ":)\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}