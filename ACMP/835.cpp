#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int i, vector<int> &itemWeight, vector<int> &itemPrice, long long weightLimit, long long curWeight,
         long long curPrice, vector<int> &curItems, long long &resPrice, vector<int> &resItems) {
    if (curWeight > weightLimit)
        return;

    if (resPrice < curPrice || resPrice == curPrice && resItems.size() > curItems.size() ||
        resPrice == curPrice && resItems.size() == curItems.size() && resItems > curItems) {
        resPrice = curPrice;
        resItems = curItems;
    }

    if (i == itemWeight.size())
        return;

    rec(i + 1, itemWeight, itemPrice, weightLimit, curWeight, curPrice, curItems, resPrice, resItems);

    curItems.push_back(i + 1);
    rec(i + 1, itemWeight, itemPrice, weightLimit, curWeight + itemWeight[i], curPrice + itemPrice[i], curItems, resPrice, resItems);
    curItems.pop_back();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int itemCount, weightLimit;
    cin >> itemCount >> weightLimit;

    vector<int> itemWeight(itemCount), itemPrice(itemCount);
    for (int i = 0; i < itemCount; i++)
        cin >> itemWeight[i] >> itemPrice[i];

    long long resPrice = -1;
    vector<int> curItems, resItems;
    rec(0, itemWeight, itemPrice, weightLimit, 0, 0, curItems, resPrice, resItems);

    cout << resItems.size() << " " << resPrice << "\n";
    for (int item : resItems)
        cout << item << " ";
}