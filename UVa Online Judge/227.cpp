#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    vector<string> a(5);
    for (string &row : a)
        if (!getline(cin, row))
            return 0;
    
    int sy, sx;
    for (int y = 0; y < 5; y++) {
        int x = a[y].find(' ');
        if (x != -1) {
            sy = y;
            sx = x;
            break;
        }
    }

    static map<char, int> dy = { {'A', -1}, {'B', 1} };
    static map<char, int> dx = { {'L', -1}, {'R', 1} };

    bool invalid = 0;
    while (1) {
        char c;
        cin >> c;

        if (c == '0') {
            cin.ignore();
            break;
        }

        int ty = sy + dy[c], tx = sx + dx[c];
        if (0 <= ty && ty <= 4 && 0 <= tx && tx <= 4 && (ty != sy || tx != sx)) {
            swap(a[sy][sx], a[ty][tx]);
            sy = ty;
            sx = tx;
        } else {
            invalid = 1;
        }
    }

    if (test > 1)
        cout << "\n";
    cout << "Puzzle #" << test << ":\n";
    if (invalid) {
        cout << "This puzzle has no final configuration.\n";
    } else {
        for (string &row : a)
            for (int i = 0; i < 5; i++)
                cout << row[i] << (i < 4 ? ' ' : '\n');
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}