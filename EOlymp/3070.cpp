#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> sums(size);
    partial_sum(a.begin(), a.end(), sums.begin());

    int from = 0;
    multiset<int> sumSet(sums.begin(), sums.end());
    int res = from <= *sumSet.begin();

    for (int i = 0; i < a.size(); i++) {
        sums.push_back(sums.back() + a[i]);
        from += a[i];
        sumSet.erase(sumSet.find(sums[i]));
        sumSet.insert(sums.back());
        res += from <= *sumSet.begin();
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}