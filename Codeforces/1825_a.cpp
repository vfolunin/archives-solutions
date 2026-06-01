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

    if (unordered_set<char>(s.begin(), s.end()).size() == 1)
        cout << "-1\n";
    else
        cout << s.size() - 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}