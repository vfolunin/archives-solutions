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

    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    sort(a.rbegin(), a.rend());

    vector<pair<int, int>> b(bSize);
    for (auto &[limit, price] : b)
        cin >> limit >> price;

    sort(b.begin(), b.end(), [](auto &lhs, auto &rhs) {
        return lhs.second > rhs.second;
    });

    long long res = 0;
    int i = 0;
    for (auto &[limit, price] : b)
        for (; i < a.size() && limit; i++, limit--)
            res += 1LL * a[i] * price;
    
    cout << res;
}