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

    vector<int> a(size), pos(size);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }

    vector<pair<int, int>> res;
    for (int i = 0; i + 1 < a.size(); i++) {
        for (int j = a[i]; j > i; j--) {
            res.push_back({ pos[j], pos[j - 1] });
            swap(a[pos[j]], a[pos[j - 1]]);
            swap(pos[j], pos[j - 1]);
        }
    }

    cout << res.size() << "\n";
    for (auto &[a, b] : res)
        cout << a + 1 << " " << b + 1 << "\n";
}