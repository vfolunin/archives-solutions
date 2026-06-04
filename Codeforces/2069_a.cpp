#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    getline(cin, s);
    getline(cin, s);

    cout << (s.find("1 0 1") != -1 ? "NO\n" : "YES\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;
    cin.ignore();

    for (int test = 0; test < testCount; test++)
        solve();
}