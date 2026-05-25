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

    int res = 0;
    for (int l = 0, r = 0; l < a.size(); l++, r = max(l, r)) {
        while (r + 1 < a.size() && a[l] > a[r + 1])
            r++;
        res = max(res, r - l + 1);
    }

    cout << res - 1;
}