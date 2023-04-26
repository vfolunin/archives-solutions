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

    int initialCost, deltaCost, depth;
    cin >> initialCost >> deltaCost >> depth;

    int cost = 0;
    for (int i = 0; i < depth; i++)
        cost += initialCost + i * deltaCost;

    cout << cost;
}