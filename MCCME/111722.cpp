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

    int itemCount, weightLimit;
    cin >> itemCount >> weightLimit;

    vector<int> itemWeight(itemCount), itemPrice(itemCount);
    for (int i = 0; i < itemCount; i++)
        cin >> itemWeight[i] >> itemPrice[i];

    long long resPrice = -1;
    vector<int> resItems;

    for (int mask = 0; mask < (1 << itemCount); mask++) {
        long long curWeight = 0, curPrice = 0;
        vector<int> curItems;

        for (int bit = 0; bit < itemCount; bit++) {
            if (mask & (1 << bit)) {
                curWeight += itemWeight[bit];
                curPrice += itemPrice[bit];
                curItems.push_back(bit + 1);
            }
        }

        if (curWeight <= weightLimit && (resPrice < curPrice ||
            resPrice == curPrice && resItems.size() > curItems.size() ||
            resPrice == curPrice && resItems.size() == curItems.size() && resItems > curItems)) {
            resPrice = curPrice;
            resItems = curItems;
        }
    }

    cout << resItems.size() << " " << resPrice << "\n";
    for (int item : resItems)
        cout << item << " ";
}