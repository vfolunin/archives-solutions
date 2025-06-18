#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<pair<int, int>> res;
    for (int i = 0; i < a.size(); i++) {
        while (a[i] != i) {
            res.push_back({ i, a[i] });
            swap(a[i], a[a[i]]);
        }
    }

    cout << res.size() << "\n";
    for (auto &[l, r] : res)
        cout << l << " " << r << "\n";
}