#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;
    cin.ignore();

    string s;
    getline(cin, s);

    cout << string((size - s.size() + 1) / 2, '*') << s << string((size - s.size()) / 2, '*') << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}