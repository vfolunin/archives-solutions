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

    vector<pair<int, int>> res1, res2;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            char c;
            cin >> c;

            if (((y + x) % 2) ^ (c == 'B'))
                res1.push_back({ y, x });
            else
                res2.push_back({ y, x });
        }
    }

    if (res1.size() > res2.size())
        res1.swap(res2);

    cout << res1.size() << "\n";
    for (auto &[y, x] : res1)
        cout << y + 1 << " " << x + 1 << "\n";
}