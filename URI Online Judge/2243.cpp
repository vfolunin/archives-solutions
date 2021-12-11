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

    vector<int> height(size);
    for (int &h : height)
        cin >> h;

    vector<int> l(size);
    l[0] = 1;
    for (int i = 1; i < size; i++)
        l[i] = min(l[i - 1] + 1, height[i]);

    vector<int> r(size);
    r[size - 1] = 1;
    for (int i = size - 2; i >= 0; i--)
        r[i] = min(r[i + 1] + 1, height[i]);

    int res = 0;
    for (int i = 0; i < size; i++)
        res = max(res, min(l[i], r[i]));

    cout << res << "\n";
}