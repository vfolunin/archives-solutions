#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string line;
    getline(cin, line);

    map<int, int> count;
    for (char c : line)
        count[tolower(c)]++;

    string res = "a";
    for (char c = 'b'; c <= 'z'; c++) {
        if (count[c] > count[res[0]])
            res = c;
        else if (count[c] == count[res[0]])
            res += c;
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