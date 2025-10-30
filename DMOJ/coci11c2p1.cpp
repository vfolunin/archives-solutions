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

    vector<int> a(8);
    for (int &value : a)
        cin >> value;

    vector<int> order(8);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int l, int r) {
        return a[l] > a[r];
    });

    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += a[order[i]];

    sort(order.begin(), order.begin() + 5);

    cout << sum << "\n";
    for (int i = 0; i < 5; i++)
        cout << order[i] + 1 << " ";
}