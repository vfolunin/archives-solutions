#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class SparseTable {
    vector<int> lg;
    vector<vector<pair<int, int>>> st;

public:
    SparseTable(vector<int> &a) {
        lg.resize(a.size() + 1);
        for (int i = 2; i <= a.size(); i++)
            lg[i] = lg[i / 2] + 1;

        st.emplace_back();
        for (int i = 0; i < a.size(); i++)
            st[0].push_back({ a[i], i });

        for (int level = 1, levelWidth = 2; levelWidth <= a.size(); level++, levelWidth *= 2) {
            st.emplace_back();
            for (int i = 0; i + (1 << level) <= a.size(); i++) {
                pair<int, int> pl = st[level - 1][i];
                pair<int, int> pr = st[level - 1][i + levelWidth / 2];
                st[level].push_back(pl.first >= pr.first ? pl : pr);
            }
        }
    }

    pair<int, int> getMax(int l, int r) {
        int level = lg[r - l + 1], levelWidth = 1 << level;
        pair<int, int> pl = st[level][l];
        pair<int, int> pr = st[level][r - levelWidth + 1];
        return pl.first >= pr.first ? pl : pr;
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

    SparseTable st(a);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        auto [value, index] = st.getMax(l - 1, r - 1);
        cout << value << " " << index + 1 << "\n";
    }
}