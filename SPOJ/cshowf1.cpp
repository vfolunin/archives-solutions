#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, y1, x1, y2, x2;
    cin >> size >> y1 >> x1 >> y2 >> x2;
    y1--;
    x1--;
    y2--;
    x2--;
    
    vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
    vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };
    set<pair<int, int>> attacked = { { y1, x1 }, { y2, x2 } };

    for (auto &[y, x] : vector<pair<int, int>>{ { y1, x1 }, { y2, x2 } }) {
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < size && 0 <= tx && tx < size)
                attacked.insert({ ty, tx });
        }
    }

    cout << size * size - attacked.size() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}