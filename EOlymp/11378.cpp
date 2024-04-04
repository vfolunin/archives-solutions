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

    vector<pair<int, int>> a(3);
    for (auto &[num, den] : a)
        cin >> den;
    for (auto &[num, den] : a)
        cin >> num;

    int res = 1e9;
    for (auto &[num, den] : a)
        res = min(res, num / den);

    cout << res;
}