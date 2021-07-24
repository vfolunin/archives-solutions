#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void find(vector<string> &a, string &s) {
    cout << "\n" << s << "\n";

    bool found = 0;
    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a.size(); x++) {
            if (a[y][x] != s[0])
                continue;

            static int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
            static int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
            static string ds[] = { "N", "NE", "E", "SE", "S", "SW", "W", "NW" };

            for (int d = 0; d < 8; d++) {
                bool ok = 1;
                for (int i = 1, step = 1; i < s.size(); step++) {
                    int ty = y + dy[d] * step, tx = x + dx[d] * step;
                    if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size() && (a[ty][tx] == s[i] || a[ty][tx] == ' ')) {
                        if (a[ty][tx] == s[i])
                            i++;
                    } else {
                        ok = 0;
                        break;
                    }
                }

                if (ok) {
                    found = 1;
                    cout << "(" << y + 1 << "," << x + 1 << ") - " << ds[d] << "\n";
                }
            }
        }
    }

    if (!found)
        cout << "not found\n";
}

void solve(int test) {
    int size;
    cin >> size;
    cin.ignore();

    vector<string> a(size);
    for (string &row : a)
        getline(cin, row);

    if (test)
        cout << "\n";

    while (1) {
        string s;
        if (!(getline(cin, s)) || s.empty())
            break;

        find(a, s);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}