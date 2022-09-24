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

    vector<int> count = { 1, 5, 10, 20, 60 };
    vector<int> price = { 15, 70, 125, 230, 440 };

    vector<int> cost(n + 100, 1e9);
    vector<vector<int>> tickets(n + 100, vector<int>(5));
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

    int resI = n;
    for (int i = n + 1; i < cost.size(); i++)
        if (cost[resI] >= cost[i])
            resI = i;

    for (int count : tickets[resI])
        cout << count << " ";
}