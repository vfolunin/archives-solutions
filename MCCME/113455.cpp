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

    vector<int> a(3);
    int sum = 0;
    for (int &value : a) {
        cin >> value;
        sum += value;
    }

    vector<int> order = { 0, 1, 2 };
    sort(order.begin(), order.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    if (a[order[0]] + a[order[1]] == a[order[2]]) {
        cout << 0;
        return 0;
    }

    cout << order[2] + 1 << "\n";
    cout << sum / 2 - a[order[0]] << " " << sum / 2 - a[order[1]];
}