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

    int m = count(line.begin(), line.end(), 'M');
    int f = count(line.begin(), line.end(), 'F');

    cout << (m == f && m > 1 ? "LOOP\n" : "NO LOOP\n");
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