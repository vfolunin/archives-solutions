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

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<pair<int, int>> res;
    while (1) {
        bool found = 0;
        for (int i = 0; i < a.size(); i++) {
            int j = (i + 1) % a.size();
            if (a[i] + 1 < a[j]) {
                res.push_back({ a[i], a[j] });
                swap(a[i], a[j]);
                found = 1;
            }
        }
        if (!found)
            break;
    }

    bool ok = 1;
    for (int i = 0; ok && i < a.size(); i++) {
        int j = (i + 1) % a.size();
        ok &= a[i] + 1 == a[j] || a[i] == a.size() && a[j] == 1;
    }

    if (ok) {
        for (auto &[a, b] : res)
            cout << a << " " << b << "\n";
        cout << 0;
    } else {
        cout << -1;
    }
}