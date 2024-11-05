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

    vector<int> l(size, 1);
    for (int i = 1; i < size; i++)
        l[i] = min(l[i - 1] + 1, a[i]);

    vector<int> r(size, 1);
    for (int i = size - 2; i >= 0; i--)
        r[i] = min(r[i + 1] + 1, a[i]);

    int res = 0;
    for (int i = 0; i < size; i++)
        res = max(res, min(l[i], r[i]));

    cout << res;
}