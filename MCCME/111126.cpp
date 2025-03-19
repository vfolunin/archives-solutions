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

    int size, diff;
    cin >> size >> diff;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> order(size);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int lhs, int rhs) {
        return a[lhs] < a[rhs];
    });

    int cur = 1, res = 1, resFrom = 0;
    for (int i = 1; i < order.size(); i++) {
        if (a[order[i]] - a[order[i - 1]] <= diff) {
            cur++;
        } else {
            if (res < cur) {
                res = cur;
                resFrom = i - res;
            }
            cur = 1;
        }
    }
    if (res < cur) {
        res = cur;
        resFrom = order.size() - res;
    }

    cout << res << "\n";
    for (int i = 0; i < res; i++)
        cout << order[resFrom + i] + 1 << " ";
}