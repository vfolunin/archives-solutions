#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int h, w;
    cin >> h >> w;
    cin.ignore(1);

    vector<string> a(h);
    for (string &row : a)
        getline(cin, row);

    int y, x, d = 0;
    cin >> y >> x;
    y--;
    x--;

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    while (1) {
        char op;
        cin >> op;

        if (op == 'R') {
            d = (d + 1) % 4;
        } else if (op == 'L') {
            d = (d + 3) % 4;
        } else if (op == 'F') {
            if (a[y + dy[d]][x + dx[d]] == ' ') {
                y += dy[d];
                x += dx[d];
            }
        } else {
            break;
        }
    }

    if (test)
        cout << "\n";
    cout << y + 1 << " " << x + 1 << " " << "NESW"[d] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}