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

    int aSize;
    cin >> aSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    int bSize;
    cin >> bSize;

    vector<pair<int, int>> b(bSize);
    for (auto &[power, price] : b)
        cin >> power >> price;

    sort(b.begin(), b.end());
    for (int i = bSize - 2; i >= 0; i--)
        b[i].second = min(b[i].second, b[i + 1].second);

    int res = 0;
    for (int value : a)
        res += lower_bound(b.begin(), b.end(), make_pair(value, 0))->second;

    cout << res;
}