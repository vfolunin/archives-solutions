#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> getPos(char c) {
    if (c == '0')
        return { 3, 1 };
    return { (c - '1') / 3, (c - '1') % 3 };
}

bool check(int n) {
    pair<int, int> pos = { 0, 0 };
    for (char c : to_string(n)) {
        pair<int, int> nextPos = getPos(c);
        if (pos.first > nextPos.first || pos.second > nextPos.second)
            return 0;
        pos = nextPos;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; 1; i++) {
        for (int value : { n - i, n + i }) {
            if (check(value)) {
                cout << value << "\n";
                return;
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}