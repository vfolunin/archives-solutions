#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SparseTable {
    vector<int> log;
    vector<vector<int>> st;

    SparseTable(vector<int> &a) {
        log = { 0, 0 };
        for (int i = 2; i <= a.size(); i++)
            log.push_back(log[i / 2] + 1);

        st.push_back(a);
        for (int level = 1, width = 2; width <= a.size(); level++, width *= 2) {
            st.emplace_back();
            for (int from = 0; from + width <= a.size(); from++)
                st[level].push_back(min(st[level - 1][from], st[level - 1][from + width / 2]));
        }
    }

    int getMin(int l, int r) {
        int level = log[r - l + 1], width = 1 << level;
        return min(st[level][l], st[level][r - width + 1]);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, queryCount;
    cin >> n >> queryCount;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    SparseTable st(a);

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        cout << st.getMin(l - 1, r - 1) << "\n";
    }
}