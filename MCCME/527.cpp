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

    vector<int> order(size);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int lhs, int rhs) {
        return a[lhs] > a[rhs];
    });

    int cost = 0;
    for (int i = 0; i < size; i++)
        cost += a[order[i]] * (i + 1);

    cout << cost << "\n";
    for (int i : order)
        cout << i + 1 << " ";
}