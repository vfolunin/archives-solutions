#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string s;
    int queryCount;
    cin >> s >> queryCount;
    int size = s.size() * 2 - 1;

    cout << "Square " << test << ":\n";
    for (int queryIndex = 1; queryIndex <= queryCount; queryIndex++) {
        cout << "Query " << queryIndex << ":\n";

        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++)
                cout << s[min(min(y - 1, size - y), min(x - 1, size - x))];
            cout << "\n";
        }
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}