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

    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;

    vector<int> aOrder(aSize);
    iota(aOrder.begin(), aOrder.end(), 0);
    sort(aOrder.begin(), aOrder.end(), [&](int lhs, int rhs) {
        return a[lhs] < a[rhs];
    });

    vector<int> bOrder(bSize);
    iota(bOrder.begin(), bOrder.end(), 0);
    sort(bOrder.begin(), bOrder.end(), [&](int lhs, int rhs) {
        return b[lhs] > b[rhs];
    });

    vector<pair<int, int>> res;
    int i = 0;
    for (int ai : aOrder)
        if (i < bOrder.size() && a[ai] < b[bOrder[i]])
            res.push_back({ ai, bOrder[i++] });

    cout << res.size() << "\n";
    for (auto &[ai, bi] : res)
        cout << ai + 1 << " " << bi + 1 << "\n";
}