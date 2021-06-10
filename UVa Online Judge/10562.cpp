#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<string> &lines, int y, int x) {
    cout << lines[y][x] << "(";

    if (y + 3 < lines.size() && lines[y + 1][x] == '|') {
        int l = x, r = x;
        while (0 <= l - 1 && lines[y + 2][l - 1] == '-')
            l--;
        while (r + 1 < lines[y + 2].size() && lines[y + 2][r + 1] == '-')
            r++;

        for (int x = l; x <= r && x < lines[y + 3].size(); x++)
            if (lines[y + 3][x] != ' ')
                rec(lines, y + 3, x);
    }

    cout << ")";
}

void solve() {
    vector<string> lines;
    while (1) {
        string line;
        getline(cin, line);

        if (line == "#")
            break;

        lines.push_back(line);
    }

    cout << "(";
    if (!lines.empty()) {
        int x = 0;
        while (lines[0][x] == ' ')
            x++;
        rec(lines, 0, x);
    }
    cout << ")\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}