#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

template<typename F>
class SparseTable {
    vector<int> lg;
    vector<vector<int>> st;
    F f;

public:
    SparseTable(vector<int> &a, F f) : f(f) {
        lg.resize(a.size() + 1);
        for (int i = 2; i <= a.size(); i++)
            lg[i] = lg[i / 2] + 1;

        st.push_back(a);
        for (int level = 1, levelWidth = 2; levelWidth <= a.size(); level++, levelWidth *= 2) {
            st.emplace_back();
            for (int i = 0; i + levelWidth <= a.size(); i++)
                st[level].push_back(f(st[level - 1][i], st[level - 1][i + levelWidth / 2]));
        }
    }

    int get(int l, int r) {
        int level = lg[r - l + 1], levelWidth = 1 << level;
        return f(st[level][l], st[level][r - levelWidth + 1]);
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

    SparseTable sparseTableMax(a, [](int a, int b) { return max(a, b); });
    SparseTable sparseTableOr(a, [](int a, int b) { return a | b; });

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string type;
        int l, r;
        cin >> type >> l >> r;
        l--;
        r--;

        if (type == "AND")
            cout << sparseTableMax.get(l, r) << "\n";
        else
            cout << sparseTableOr.get(l, r) << "\n";
    }
}