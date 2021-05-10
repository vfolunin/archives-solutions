#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int x, y;
    string s;
    cin >> x >> y >> s;

    vector<string> a(32, string(32, '.'));

    for (char c : s) {
        if (c == 'N') {
            y++;
            a[y - 1][x] = 'X';
        } else if (c == 'E') {
            x++;
            a[y - 1][x - 1] = 'X';
        } else if (c == 'S') {
            y--;
            a[y][x - 1] = 'X';
        } else if (c == 'W') {
            x--;
            a[y][x] = 'X';
        }
    }

    cout << "Bitmap #" << test << "\n";
    for (int y = a.size() - 1; y >= 0; y--)
        cout << a[y] << "\n";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}