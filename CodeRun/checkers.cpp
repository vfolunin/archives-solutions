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

    int h, w;
    cin >> h >> w;

    int aSize;
    cin >> aSize;

    set<pair<int, int>> a;
    for (int i = 0; i < aSize; i++) {
        int y, x;
        cin >> y >> x;
        a.insert({ y, x });
    }

    int bSize;
    cin >> bSize;

    set<pair<int, int>> b;
    for (int i = 0; i < bSize; i++) {
        int y, x;
        cin >> y >> x;
        b.insert({ y, x });
    }

    string player;
    cin >> player;

    if (player == "black")
        swap(a, b);

    for (auto &[y, x] : a) {
        static vector<int> dy = { -1, -1, 1, 1 };
        static vector<int> dx = { -1, 1, 1, -1 };

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            int ty2 = ty + dy[d];
            int tx2 = tx + dx[d];

            if (1 <= ty2 && ty2 <= h && 1 <= tx2 && tx2 <= w &&
                b.count({ ty, tx }) && !a.count({ ty2, tx2 }) && !b.count({ ty2, tx2 })) {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
}