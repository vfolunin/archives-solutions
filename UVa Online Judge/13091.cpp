#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    vector<string> a(5);
    for (string &row : a)
        cin >> row;

    cout << "Case " << test << ": ";

    for (string &row : a) {
        int pos = row.find('>');
        if (pos != -1) {
            cout << (pos > row.find('|') ? "No" : "Thik") << " Ball\n";
            return;
        }

        pos = row.find('<');
        if (pos != -1) {
            cout << (pos < row.find('|') ? "No" : "Thik") << " Ball\n";
            return;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}