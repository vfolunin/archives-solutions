#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string line;
    getline(cin, line);

    int n = sqrt(line.size());
    if (n * n != line.size()) {
        cout << "INVALID\n";
    } else {
        for (int i = 0; i < line.size(); i++)
            cout << line[i % n * n + i / n];
        cout << "\n";
    }
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