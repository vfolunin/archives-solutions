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

    set<int> l, r(a.begin(), a.end());
    vector<int> res;

    for (int i = 0; i < size - 1; i++) {
        l.insert(a[i]);
        r.erase(a[i]);
        if (*prev(l.end()) < *r.begin())
            res.push_back(i + 1);
    }

    cout << res.size() << "\n";
    for (int value : res)
        cout << value << " ";
}