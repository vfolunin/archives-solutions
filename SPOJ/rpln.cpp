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
        int level = lg[r - l + 1], levelWidth = 1 << level;
        return min(st[level][l], st[level][r - levelWidth + 1]);
    }
};

void solve(int test) {
    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    SparseTable sparseTable(a);
    cout << "Scenario #" << test << ":\n";

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;

        cout << sparseTable.getMin(l - 1, r - 1) << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}