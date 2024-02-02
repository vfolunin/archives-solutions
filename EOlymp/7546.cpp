#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    unordered_set<string> values;
    for (int i = 0; i < size; i++) {
        string value;
        cin >> value;
        values.insert(value);
    }

    cout << values.size() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}