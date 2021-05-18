#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int chamberCount, peopleCount;
    if (!(cin >> chamberCount >> peopleCount))
        return 0;

    vector<int> weight(peopleCount);
    double averageWeight = 0;
    for (int &w : weight) {
        cin >> w;
        averageWeight += w;
    }
    while (weight.size() < chamberCount * 2)
        weight.push_back(0);
    sort(weight.begin(), weight.end());
    averageWeight /= chamberCount;

    vector<vector<int>> chamber(chamberCount);
    double imbalance = 0;
    for (int i = 0, j = weight.size() - 1; i < chamberCount; i++, j--) {
        if (weight[i])
            chamber[i].push_back(weight[i]);
        if (weight[j])
            chamber[i].push_back(weight[j]);
        imbalance += abs(weight[i] + weight[j] - averageWeight);
    }

    cout << "Set #" << test << "\n";
    for (int i = 0; i < chamberCount; i++) {
        cout << " " << i << ":";
        for (int w : chamber[i])
            cout << " " << w;
        cout << "\n";
    }
    cout.precision(5);
    cout << "IMBALANCE = " << fixed << imbalance << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}