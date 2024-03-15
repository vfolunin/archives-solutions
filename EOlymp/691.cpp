#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class SparseTable {
    vector<int> lg;
    vector<vector<int>> st;

public:
    SparseTable(vector<int> &a) {
        lg.resize(a.size() + 1);
        for (int i = 2; i <= a.size(); i++)
            lg[i] = lg[i / 2] + 1;

        st.push_back(a);
        for (int level = 1, levelWidth = 2; levelWidth <= a.size(); level++, levelWidth *= 2) {
            st.emplace_back();
            for (int i = 0; i + levelWidth <= a.size(); i++)
                st[level].push_back(min(st[level - 1][i], st[level - 1][i + levelWidth / 2]));
        }
    }

    int getMin(int l, int r) {
        if (l > r)
            swap(l, r);
        int level = lg[r - l + 1], levelWidth = 1 << level;
        return min(st[level][l], st[level][r - levelWidth + 1]);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> a(size);
    cin >> a[0];
    for (int i = 1; i < a.size(); i++)
        a[i] = (23 * a[i - 1] + 21563) % 16714589;

    SparseTable sparseTable(a);

    int l, r;
    cin >> l >> r;

    int res = sparseTable.getMin(l - 1, r - 1);

    for (int i = 1; i < queryCount; i++) {
        l = (17 * l + 751 + res + 2 * i) % size + 1;
        r = (13 * r + 593 + res + 5 * i) % size + 1;
        res = sparseTable.getMin(l - 1, r - 1);
    }

    cout << l << " " << r << " " << res;
}