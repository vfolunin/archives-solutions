#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getLd() {
    vector<int> ld(100010);
    for (int i = 1; i < ld.size(); i++)
        ld[i] = ld[i / 2] + 1;
    return ld;
}

int minH(int n) {
    static vector<int> ld = getLd();
    return ld[n];
}

int maxH(int n) {
    return n;
}

void make(int l, int r, int h, vector<int> &tree) {
    if (l > r)
        return;
    for (int i = l; i <= r; i++) {
        if (minH(r - i) <= h - 1) {
            tree.push_back(i);
            make(l, i - 1, h - 1, tree);
            make(i + 1, r, h - 1, tree);
            return;
        }
    }
}

bool solve(int test) {
    int n, h;
    cin >> n >> h;

    if (!n && !h)
        return 0;

    cout << "Case " << test << ": ";
    if (h < minH(n)) {
        cout << "Impossible.\n";
    } else {
        vector<int> tree;
        make(1, n, h, tree);
        for (int i = 0; i < n; i++)
            cout << tree[i] << (i + 1 < n ? " " : "\n");
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}