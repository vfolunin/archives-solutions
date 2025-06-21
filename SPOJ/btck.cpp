#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(vector<int> &a, int i, vector<int> &used, vector<int> &res, long long sum, int limit) {
    if (i == a.size()) {
        if (sum <= limit) {
            for (int value : res)
                cout << value << " ";
            cout << "\n";
            return 1;
        }
        return 0;
    }

    if (sum > limit)
        return 0;

    for (int value = 0; value < a.size(); value++) {
        if (!used[value]) {
            used[value] = 1;
            res.push_back(value);
            if (rec(a, i + 1, used, res, sum + a[i] * value, limit))
                return 1;
            used[value] = 0;
            res.pop_back();
        }
    }

    return 0;
}

void solve() {
    vector<int> a(10);
    for (int &value : a)
        cin >> value;

    int limit;
    cin >> limit;

    vector<int> used(a.size()), res;
    if (!rec(a, 0, used, res, 0, limit))
        cout << "-1\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}