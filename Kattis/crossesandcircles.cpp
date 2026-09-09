#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> ask(int y, int x, set<pair<int, int>> &used) {
    cout << y << " " << x << endl;
    used.insert({ y, x });

    cin >> y >> x;
    used.insert({ y, x });
    return { y, x };
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int y1 = 10, x1 = 10;
    set<pair<int, int>> used;

    auto [y2, x2] = ask(y1, x1, used);

    vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
    vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };

    for (int d = 0, dr = dy.size() / 2; dr < dy.size(); d++, dr++) {
        int y3 = y1 + dy[d];
        int x3 = x1 + dx[d];
        int ya = y3 + dy[d];
        int xa = x3 + dx[d];
        int yb = y1 + dy[dr];
        int xb = x1 + dx[dr];
        if (used.contains({ y3, x3 }) || used.contains({ ya, xa }) || used.contains({ yb, xb }))
            continue;

        ask(y3, x3, used);

        if (!used.contains({ ya, xa }))
            ask(ya, xa, used);
        else
            ask(yb, xb, used);
        break;
    }
}