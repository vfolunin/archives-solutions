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

    int breakCount, breakPrice;
    cin >> breakCount >> breakPrice;

    int curProfit = 0, maxProfit = 0;

    for (int i = 0; i < breakCount; i++) {
        int breakProfit;
        cin >> breakProfit;

        breakProfit -= breakPrice;
        curProfit = max(curProfit, 0) + breakProfit;
        maxProfit = max(maxProfit, curProfit);
    }

    cout << maxProfit;
}