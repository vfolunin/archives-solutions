#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool find(vector<string> &a, vector<string> &b, int fromY, int fromX) {
    for (int y = 0; y < b.size(); y++)
        for (int x = 0; x < b.size(); x++)
            if (a[fromY + y][fromX + x] != b[y][x])
                return 0;
    return 1;
}

int count(vector<string> &a, vector<string> &b) {
    int res = 0;
    for (int y = 0; y + b.size() <= a.size(); y++)
        for (int x = 0; x + b.size() <= a.size(); x++)
            res += find(a, b, y, x);
    return res;
}

void rotate(vector<string> &a) {
    for (int y = 0; y < a.size() / 2; y++) {
        for (int x = 0; x < (a.size() + 1) / 2; x++) {
            swap(a[y][x], a[a.size() - 1 - x][y]);
            swap(a[a.size() - 1 - x][y], a[a.size() - 1 - y][a.size() - 1 - x]);
            swap(a[a.size() - 1 - y][a.size() - 1 - x], a[x][a.size() - 1 - y]);
        }
    }
}

bool solve() {
    int aSize, bSize;
    cin >> aSize >> bSize;

    if (!aSize && !bSize)
        return 0;

    vector<string> a(aSize);
    for (string &row : a)
        cin >> row;

    vector<string> b(bSize);
    for (string &row : b)
        cin >> row;

    for (int i = 0; i < 4; i++) {
        cout << count(a, b) << (i < 3 ? ' ' : '\n');
        rotate(b);
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}