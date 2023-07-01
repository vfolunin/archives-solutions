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

    set<int> seen;
    vector<int> res;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (!seen.count(a[i])) {
            seen.insert(a[i]);
            res.push_back(a[i]);
        }
    }

    cout << res.size() << "\n";
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << " ";
}