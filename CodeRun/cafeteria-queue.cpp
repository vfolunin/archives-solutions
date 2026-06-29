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

void solve() {
    int size, time;
    cin >> size >> time;

    vector<int> a(size);
    int timeSum = 0;

    for (int i = 0; i < size; i++) {
        int value, time;
        cin >> value >> time;

        a[i] = value - timeSum;
        timeSum += time;
    }

    SparseTable sparseTable(a);

    int l = -1, r = a.size();
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (sparseTable.getMin(m, size - 1) < time)
            l = m;
        else
            r = m;
    }

    cout << r + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}