#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int n, int from, vector<int> &parts) {
    if (!n) {
        for (int part : parts)
            cout << part << " ";
        cout << "\n";
        return;
    }

    for (int i = from; i <= n; i++) {
        parts.push_back(i);
        rec(n - i, i, parts);
        parts.pop_back();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> parts;
    rec(n, 1, parts);
}