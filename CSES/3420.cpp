#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
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

    unordered_set<int> values;
    long long res = 0;
    for (int l = 0, r = 0; r < a.size(); r++) {
        while (values.count(a[r]))
            values.erase(a[l++]);
        values.insert(a[r]);
        res += r - l + 1;
    }

    cout << res;
}