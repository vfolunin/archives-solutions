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

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> cost(1 << a.size(), 1e9);
    cost[0] = 0;

    for (int mask = 1; mask < (1 << a.size()); mask++) {
        for (int from = 0; from < a.size(); from++) {
            int nextMask = mask;
            for (int bit = 0; bit < 3; bit++)
                nextMask &= ~(1 << ((from + bit) % a.size()));

            int price = 0;
            for (int bit = 0; bit < a.size(); bit++)
                if (nextMask & (1 << bit))
                    price += a[bit];

            cost[mask] = min(cost[mask], cost[nextMask] + price);
        }
    }

    cout << cost.back();
}