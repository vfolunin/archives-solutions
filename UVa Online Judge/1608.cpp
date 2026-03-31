#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

bool check(vector<int> &a, vector<int> &leftIndex, vector<int> &rightIndex, int l, int r) {
    if (l >= r)
        return 0;

    for (int m1 = l, m2 = r; m1 <= r; m1++, m2--) {
        if (leftIndex[m1] < l && r < rightIndex[m1])
            return check(a, leftIndex, rightIndex, l, m1 - 1) || check(a, leftIndex, rightIndex, m1 + 1, r);
        if (leftIndex[m2] < l && r < rightIndex[m2])
            return check(a, leftIndex, rightIndex, l, m2 - 1) || check(a, leftIndex, rightIndex, m2 + 1, r);
    }
    return 1;
}

void solve() {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    unordered_map<int, int> last;
    vector<int> leftIndex(a.size(), -1);
    for (int i = 0; i < a.size(); i++) {
        if (auto it = last.find(a[i]); it != last.end())
            leftIndex[i] = it->second;
        last[a[i]] = i;
    }

    last.clear();
    vector<int> rightIndex(a.size(), a.size());
    for (int i = a.size() - 1; i >= 0; i--) {
        if (auto it = last.find(a[i]); it != last.end())
            rightIndex[i] = it->second;
        last[a[i]] = i;
    }

    cout << (check(a, leftIndex, rightIndex, 0, a.size() - 1) ? "boring\n" : "non-boring\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}