#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int y, vector<int> &col, vector<int> &d1, vector<int> &d2, vector<int> &p) {
    if (y == col.size()) {
        for (int y = 0; y < p.size(); y++) {
            for (int x = 0; x < p.size(); x++)
                cout << (p[y] == x) << " ";
            cout << "\n";
        }
        exit(0);
    }

    for (int x = 0; x < col.size(); x++) {
        if (col[x] || d1[y + x] || d2[y - x + col.size()])
            continue;

        col[x] = d1[y + x] = d2[y - x + col.size()] = 1;
        p[y] = x;
        rec(y + 1, col, d1, d2, p);
        col[x] = d1[y + x] = d2[y - x + col.size()] = 0;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> col(size), d1(size * 2), d2(size * 2), p(size);
    rec(0, col, d1, d2, p);

    cout << "Not possible";
}