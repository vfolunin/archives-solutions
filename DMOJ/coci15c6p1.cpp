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

    int handCount;
    char trump;
    cin >> handCount >> trump;

    string values = "AKQJT987";
    vector<int> trumpCost = { 11, 4, 3, 20, 10, 14, 0, 0 };
    vector<int> regularCost = { 11, 4, 3, 2, 10, 0, 0, 0 };

    int totalCost = 0;
    for (int i = 0; i < handCount * 4; i++) {
        string card;
        cin >> card;
        vector<int> &cost = card[1] == trump ? trumpCost : regularCost;
        totalCost += cost[values.find(card[0])];
    }

    cout << totalCost;
}