#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void construct(vector<string> &a, string &line, int &i, int y, int x, int size) {
    char c = line[i++];
    if (c == 'p') {
        size /= 2;
        construct(a, line, i, y, x + size, size);
        construct(a, line, i, y, x, size);
        construct(a, line, i, y + size, x, size);
        construct(a, line, i, y + size, x + size, size);
    } else if (c == 'f') {
        for (int i = y; i < y + size; i++)
            fill(a[i].begin() + x, a[i].begin() + x + size, '1');
    }
}

vector<string> read() {
    string line;
    cin >> line;
    vector<string> a(32, string(32, '0'));
    int i = 0;
    construct(a, line, i, 0, 0, 32);
    return a;
}

void solve() {
    vector<string> a = read();
    vector<string> b = read();

    int res = 0;
    for (int i = 0; i < 32; i++)
        for (int j = 0; j < 32; j++)
            res += a[i][j] == '1' || b[i][j] == '1';

    cout << "There are " << res << " black pixels.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}