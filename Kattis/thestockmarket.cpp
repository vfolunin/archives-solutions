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

    int size, r;
    cin >> size >> r;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int res = -1e9;
    for (int l = 0; r < a.size(); l++, r++)
        res = max(res, a[r] - a[l]);

    cout << res;
}