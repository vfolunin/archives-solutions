#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    if (unordered_set<char>(s.begin(), s.begin() + s.size() / 2).size() == 1)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}