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

    string ops;
    cin >> ops;

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };
    int y = 0, x = 0, d = 0, steps = 0;
    set<pair<int, int>> seen = { { y, x } };

    for (char op : ops) {
        if (op == 'R') {
            d = (d + 1) % dy.size();
        } else if (op == 'L') {
            d = (d + dy.size() - 1) % dy.size();
        } else {
            y += dy[d];
            x += dx[d];
            steps++;
            if (seen.count({ y, x })) {
                cout << steps;
                return 0;
            }
            seen.insert({ y, x });
        }
    }

    cout << -1;
}