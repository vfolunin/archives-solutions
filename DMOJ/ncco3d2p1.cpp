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
            st[0].push_back({ a[i], a[i] });
        for (int level = 1, levelWidth = 2; levelWidth <= a.size(); level++, levelWidth *= 2) {
            st.emplace_back();
            for (int i = 0; i + levelWidth <= a.size(); i++)
                st[level].push_back({
                    min(st[level - 1][i].first, st[level - 1][i + levelWidth / 2].first),
                    max(st[level - 1][i].second, st[level - 1][i + levelWidth / 2].second)
                    });
        }
    }

    int getDiff(int l, int r) {
        int level = lg[r - l + 1], levelWidth = 1 << level;
        int minValue = min(st[level][l].first, st[level][r - levelWidth + 1].first);
        int maxValue = max(st[level][l].second, st[level][r - levelWidth + 1].second);
        return maxValue - minValue;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    SparseTable sparseTable(a);

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        cout << sparseTable.getDiff(l, r) << "\n";
    }
}