#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    map<int, int> count;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] != '.')
                continue;

            if (!y || a[y - 1][x] != '.') {
                int size = 1;
                while (y + size < h && a[y + size][x] == '.')
                    size++;
                if (size > 1)
                    count[size]++;
            }

            if (!x || a[y][x - 1] != '.') {
                int size = 1;
                while (x + size < w && a[y][x + size] == '.')
                    size++;
                if (size > 1)
                    count[size]++;
            }
        }
    }

    for (auto &[size, count] : count)
        cout << size << "-" << count << " ";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}