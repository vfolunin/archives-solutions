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
 
    int n;
    cin >> n;

    vector<int> count = { 1, 10, 60 };
    vector<int> price = { 15, 125, 440 };

    vector<int> cost(n + 100, 1e9);
    vector<vector<int>> tickets(n + 100, vector<int>(3));
    cost[0] = 0;

    for (int i = 1; i < cost.size(); i++) {
        for (int j = 0; j < count.size(); j++) {
            if (i >= count[j] && cost[i] > cost[i - count[j]] + price[j]) {
                cost[i] = cost[i - count[j]] + price[j];
                tickets[i] = tickets[i - count[j]];
                tickets[i][j]++;
            }
        }
    }

    int resI = min_element(cost.begin() + n, cost.end()) - cost.begin();
    for (int count : tickets[resI])
        cout << count << " ";
}