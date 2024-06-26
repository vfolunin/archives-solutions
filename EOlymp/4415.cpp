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

    int sum, size;
    cin >> sum >> size;

    vector<pair<int, int>> a(size);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.rbegin(), a.rend());
    vector<int> res;

    for (auto &[value, index] : a) {
        res.push_back(index);
        if (sum > value) {
            sum -= value;
        } else {
            cout << res.size() << "\n";
            for (int index : res)
                cout << index + 1 << " ";
            return 0;
        }
    }

    cout << -1;
}