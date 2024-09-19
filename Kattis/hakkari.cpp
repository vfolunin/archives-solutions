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

    vector<pair<int, int>> res;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            char c;
            cin >> c;

            if (c == '*')
                res.push_back({ y, x });
        }
    }

    cout << res.size() << "\n";
    for (auto &[y, x] : res)
        cout << y + 1 << " " << x + 1 << "\n";
}