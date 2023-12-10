#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> indexes(a.size());
    iota(indexes.begin(), indexes.end(), 0);
    sort(indexes.begin(), indexes.end(), [&](int lhs, int rhs) {
        return a[lhs] < a[rhs];
    });

    int res = 0;
    for (int i = 1; i + 1 < indexes.size(); i++)
        if (a[indexes[res + 1]] - a[indexes[res]] > a[indexes[i + 1]] - a[indexes[i]])
            res = i;

    cout << a[indexes[res + 1]] - a[indexes[res]] << "\n";
    cout << indexes[res] + 1 << " " << indexes[res + 1] + 1;
}