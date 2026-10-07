#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s >> s;

    unordered_set<string> pairs;
    for (int i = 0; i + 1 < s.size(); i++)
        pairs.insert(s.substr(i, 2));

    cout << pairs.size() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}