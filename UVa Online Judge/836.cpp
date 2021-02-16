#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    vector<string> a;
    while (1) {
        string s;
        getline(cin, s);
        if (s.empty())
            break;
        a.push_back(s);
    }

    int h = a.size(), w = a[0].size(), maxArea = 0;

    for (int y1 = 0; y1 < h; y1++) {
        for (int y2 = y1; y2 < h; y2++) {
            for (int x1 = 0; x1 < w; x1++) {
                for (int x2 = x1; x2 < w; x2++) {

                    bool ok = 1;
                    for (int y = y1; ok && y <= y2; y++)
                        for (int x = x1; ok && x <= x2; x++)
                            ok &= a[y][x] == '1';
                    if (ok)
                        maxArea = max(maxArea, (y2 - y1 + 1) * (x2 - x1 + 1));

                }
            }
        }
    }

    if (test)
        cout << "\n";
    cout << maxArea << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}