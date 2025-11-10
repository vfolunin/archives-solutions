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

    int shareCount, moneyCount, queryCount;
    cin >> shareCount >> moneyCount >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string type;
        cin >> type;

        if (type == "DRIP") {
            int dividend, price;
            cin >> dividend >> price;

            int totalDividend = shareCount * dividend;
            shareCount += totalDividend / price;
            moneyCount += totalDividend % price;
        } else {
            int price;
            cin >> price;

            shareCount += moneyCount / price;
            moneyCount %= price;
        }
    }

    cout << shareCount << "\n" << moneyCount;
}