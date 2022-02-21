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

    int itemCount, limit;
    cin >> itemCount >> limit;

    vector<int> items(itemCount);
    for (int &item : items)
        cin >> item;

    sort(items.begin(), items.end());

    int res = 1;
    while (res < items.size() && items[res - 1] + items[res] <= limit)
        res++;

    cout << res;
}