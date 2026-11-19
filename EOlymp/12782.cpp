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
    string s;
    cin >> size >> s;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    set<int> values0;
    int res = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            values0.insert(a[i]);
        } else {
            auto it = values0.lower_bound(a[i]);
            if (it != values0.begin())
                res = max(res, *prev(it) + a[i]);
        }
    }

    cout << res;
}