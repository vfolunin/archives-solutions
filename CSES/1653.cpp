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

    int itemCount, weightLimit;
    cin >> itemCount >> weightLimit;

    vector<int> itemWeight(itemCount);
    for (int &weight : itemWeight)
        cin >> weight;

    vector<pair<int, int>> minRide(1 << itemCount, { 1e9, 1e9 });
    minRide[0] = { 1, 0 };

    for (int mask = 1; mask < (1 << itemCount); mask++) {
        for (int i = 0; i < itemCount; i++) {
            if (!(mask & (1 << i)))
                continue;

            pair<int, int> candidate = minRide[mask ^ (1 << i)];

            if (candidate.second + itemWeight[i] <= weightLimit)
                candidate.second += itemWeight[i];
            else
                candidate = { candidate.first + 1, itemWeight[i] };

            minRide[mask] = min(minRide[mask], candidate);
        }
    }

    cout << minRide.back().first;
}