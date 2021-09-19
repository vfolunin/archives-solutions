#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;
    cin.ignore();

    map<string, int> count;
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        count[line]++;
    }

    for (auto &[line, count] : count)
        cout << line << " " << count << "\n";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}