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

    int size, need;
    cin >> size >> need;

    vector<int> a(size);
    for (int &value : a) {
        int x, y;
        cin >> x >> y;
        value = x + y;
    }

    vector<int> order(a.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int lhs, int rhs) {
        return a[lhs] < a[rhs];
    });

    long long sum = 0;
    vector<int> res;
    for (int i = 0; i < need; i++) {
        sum += a[order[i]];
        res.push_back(order[i] + 1);
    }

    sort(res.begin(), res.end());

    cout << sum << "\n";
    for (int value : res)
        cout << value << " ";
}