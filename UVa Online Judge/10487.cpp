#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int find(vector<int> &v, int x) {
    auto it = lower_bound(v.begin(), v.end(), x);
    if (it == v.begin())
        return *it;
    if (it == v.end())
        return *prev(it);
    if (*it - x <= x - *prev(it))
        return *it;
    return *prev(it);
}

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> xs(n), sums;
    for (int i = 0; i < n; i++) {
        cin >> xs[i];
        for (int j = 0; j < i; j++)
            sums.push_back(xs[j] + xs[i]);
    }
    sort(sums.begin(), sums.end());

    cout << "Case " << test << ":\n";

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << "Closest sum to " << x << " is " << find(sums, x) << ".\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}