#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int commandCount;
    cin >> commandCount;

    map<int, priority_queue<int>> storage;

    for (int i = 0; i < commandCount; i++) {
        string command;
        cin >> command;

        if (command == "add") {
            int weight, profit;
            cin >> weight >> profit;
            storage[weight].push(profit);
        } else {
            int totalWeight;
            cin >> totalWeight;

            long long totalProfit = 0;

            for (auto it = storage.upper_bound(totalWeight); totalWeight && it != storage.begin(); it = storage.upper_bound(totalWeight)) {
                auto &[weight, profits] = *prev(it);
                int itemCount = min<int>(totalWeight / weight, profits.size());

                totalWeight -= itemCount * weight;
                for (int i = 0; i < itemCount; i++) {
                    totalProfit += profits.top();
                    profits.pop();
                }

                if (profits.empty())
                    storage.erase(weight);
            }

            cout << totalProfit << "\n";
        }
    }
}