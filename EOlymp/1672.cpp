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
    weightLimit *= 60;

    vector<int> itemPrice(itemCount);
    for (int &price : itemPrice)
        cin >> price;

    vector<int> itemWeight(itemCount);
    for (int &weight : itemWeight)
        cin >> weight;

    vector<int> res(weightLimit + 1);

    for (int i = 0; i < itemCount; i++)
        for (int weight = res.size() - 1; weight >= itemWeight[i]; weight--)
            res[weight] = max(res[weight], res[weight - itemWeight[i]] + itemPrice[i]);

    cout << *max_element(res.begin(), res.end());
}