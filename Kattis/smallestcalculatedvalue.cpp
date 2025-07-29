#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(vector<int> &a, int i, int cur) {
    if (i == a.size())
        return cur >= 0 ? cur : 1e9;

    int res = min({
        rec(a, i + 1, cur + a[i]),
        rec(a, i + 1, cur - a[i]),
        rec(a, i + 1, cur * a[i])
    });
    if (cur % a[i] == 0)
        res = min(res, rec(a, i + 1, cur / a[i]));
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a(3);
    for (int &value : a)
        cin >> value;

    cout << rec(a, 1, a[0]);
}