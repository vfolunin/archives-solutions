#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SparseTable {
    vector<int> lg;
    vector<vector<int>> st;

    SparseTable(vector<int> &a) {
        lg.resize(a.size() + 1);
        for (int i = 2; i <= a.size(); i++)
            lg[i] = lg[i / 2] + 1;

        st.push_back(a);
        for (int level = 1, levelWidth = 2; levelWidth <= a.size(); level++, levelWidth *= 2) {
            st.emplace_back();
            for (int i = 0; i + (1 << level) <= a.size(); i++)
                st[level].push_back(max(st[level - 1][i], st[level - 1][i + levelWidth / 2]));
        }
    }

    int getMax(int l, int r) {
        int level = lg[r - l + 1], levelWidth = 1 << level;
        return max(st[level][l], st[level][r - levelWidth + 1]);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    SparseTable sparseTable(a);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        cout << sparseTable.getMax(l - 1, r - 1) << " ";
    }
}