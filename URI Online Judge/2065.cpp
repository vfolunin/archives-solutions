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

    int cashierCount, clientCount;
    cin >> cashierCount >> clientCount;

    vector<int> cashierTime(cashierCount);
    set<pair<int, int>> cashiers;
    for (int i = 0; i < cashierCount; i++) {
        cin >> cashierTime[i];
        cashiers.insert({ 0, i });
    }

    int totalTime = 0;
    for (int i = 0; i < clientCount; i++) {
        auto [time, index] = *cashiers.begin();
        cashiers.erase(cashiers.begin());
        
        int purchaseCount;
        cin >> purchaseCount;

        time += purchaseCount * cashierTime[index];
        cashiers.insert({ time, index });
        totalTime = max(totalTime, time);
    }

    cout << totalTime << "\n";
}