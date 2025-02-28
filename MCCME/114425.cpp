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

    int cashierCount;
    cin >> cashierCount;

    vector<int> cashierTime(cashierCount);
    set<pair<long long, int>> cashierQueue;
    for (int i = 0; i < cashierCount; i++) {
        cin >> cashierTime[i];
        cashierQueue.insert({ 0, i });
    }

    int clientCount;
    cin >> clientCount;

    for (int i = 0; i < clientCount; i++) {
        int itemCount;
        cin >> itemCount;

        auto [time, cashierIndex] = *cashierQueue.begin();
        cashierQueue.erase(cashierQueue.begin());
        cashierQueue.insert({ time + 1LL * itemCount * cashierTime[cashierIndex], cashierIndex });
        
        cout << cashierIndex + 1 << " ";
    }
}