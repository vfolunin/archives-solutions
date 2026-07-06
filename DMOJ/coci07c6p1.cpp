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

    vector<int> price(3);
    for (int &p : price)
        cin >> p;

    vector<int> trucks(101);
    for (int i = 0; i < 3; i++) {
        int l, r;
        cin >> l >> r;
        for (int j = l; j < r; j++)
            trucks[j]++;
    }

    int cost = 0;
    for (int t : trucks)
        if (t)
            cost += t * price[t - 1];

    cout << cost;
}