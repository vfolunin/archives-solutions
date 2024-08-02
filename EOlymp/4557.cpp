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

    int size;
    cin >> size;

    int y = 0, x = 0;
    vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
    vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };

    set<pair<int, int>> seen = { { y, x } };
    for (int i = 1; i <= size; i++) {
        int d;
        cin >> d;
        d--;

        y += dy[d];
        x += dx[d];

        if (seen.count({ y, x })) {
            cout << i;
            return 0;
        }

        seen.insert({ y, x });
    }

    cout << "Ok\n" << abs(y) + abs(x);
}