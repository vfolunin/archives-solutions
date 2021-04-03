#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int testCount, size;
    cin >> testCount >> size;

    for (int i = 0; i < testCount; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if ((x1 + y1) % 2 != (x2 + y2) % 2)
            cout << "no move\n";
        else if (x1 == x2 && y1 == y2)
            cout << "0\n";
        else if (x1 + y1 == x2 + y2 || x1 - y1 == x2 - y2)
            cout << "1\n";
        else
            cout << "2\n";
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