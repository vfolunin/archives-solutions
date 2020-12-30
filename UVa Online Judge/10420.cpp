#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    map<string, set<string>> m;
    for (int i = 0; i < n; i++) {
        string key, val;
        cin >> key;
        getline(cin, val);
        m[key].insert(val);
    }

    for (auto &[key, vals] : m)
        cout << key << " " << vals.size() << "\n";
}