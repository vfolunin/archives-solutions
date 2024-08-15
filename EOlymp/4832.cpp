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

    int weightLimit;
    cin >> weightLimit;

    vector<int> weight;
    do {
        cin >> weight.emplace_back();
    } while (cin.peek() == ' ');

    vector<int> price(weight.size());
    for (int &p : price)
        cin >> p;

    vector<vector<int>> maxCost(weight.size() + 1, vector<int>(weightLimit + 1, -1));
    maxCost[0][0] = 0;
    vector<vector<int>> takeLast(weight.size() + 1, vector<int>(weightLimit + 1));

    for (int i = 1; i <= weight.size(); i++) {
        for (int sum = 0; sum <= weightLimit; sum++) {
            maxCost[i][sum] = maxCost[i - 1][sum];
            if (sum >= weight[i - 1] && maxCost[i - 1][sum - weight[i - 1]] != -1 &&
                maxCost[i][sum] < maxCost[i - 1][sum - weight[i - 1]] + price[i - 1]) {
                maxCost[i][sum] = maxCost[i - 1][sum - weight[i - 1]] + price[i - 1];
                takeLast[i][sum] = 1;
            }
        }
    }

    int sum = max_element(maxCost.back().begin(), maxCost.back().end()) - maxCost.back().begin();
    for (int i = weight.size(); i; i--) {
        if (takeLast[i][sum]) {
            sum -= weight[i - 1];
            cout << i << "\n";
        }
    }
}