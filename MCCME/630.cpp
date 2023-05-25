#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int n, int from, vector<int> &parts) {
    if (!n) {
        if (parts.size() > 1)
            for (int i = 0; i < parts.size(); i++)
                cout << parts[i] << (i + 1 < parts.size() ? "+" : "\n");
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