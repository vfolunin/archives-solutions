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

    int salesmanCount, callCount;
    cin >> salesmanCount >> callCount;

    set<pair<int, int>> salesmanQueue;
    for (int i = 0; i < salesmanCount; i++)
        salesmanQueue.insert({ 0, i });
    vector<int> salesmanCalls(salesmanCount);

    for (int i = 0; i < callCount; i++) {
        int duration;
        cin >> duration;

        auto [time, salesman] = *salesmanQueue.begin();
        salesmanQueue.erase(salesmanQueue.begin());
        salesmanQueue.insert({ time + duration, salesman });
        salesmanCalls[salesman]++;
    }

    for (int i = 0; i < salesmanCount; i++)
        cout << i + 1 << " " << salesmanCalls[i] << "\n";
}