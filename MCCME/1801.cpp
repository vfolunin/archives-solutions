#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w, opCount;
    cin >> h >> w >> opCount;

    if (1LL * h * w > 5 * opCount) {
        cout << "No";
        return 0;
    }

    vector<int> dy = { 0, -1, 0, 1, 0 };
    vector<int> dx = { 0, 0, 1, 0, -1 };
    unordered_set<long long> cells;

    for (int i = 0; i < opCount; i++) {
        int y, x;
        cin >> y >> x;

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (1 <= ty && ty <= h && 1 <= tx && tx <= w)
                cells.insert(1LL * ty * w + tx);
        }
    }

    cout << (1LL * h * w == cells.size() ? "Yes" : "No");
}