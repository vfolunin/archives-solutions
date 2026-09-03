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

    int itemCount;
    cin >> itemCount;

    vector<int> items(itemCount);
    for (int &item : items)
        cin >> item;

    sort(items.rbegin(), items.rend());

    vector<int> sum(2);
    for (int i = 0; i < itemCount; i++)
        sum[i % 2] += items[i];

    cout << sum[0] << " " << sum[1];
}