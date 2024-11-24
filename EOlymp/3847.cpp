#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size, width, l, r;
    if (!(cin >> size >> width >> l >> r))
        return 0;
    l--;
    r--;

    vector<int> price(size);
    multiset<pair<int, int>> prices;
    vector<int> res(r - l + 1);

    for (int i = 0; i < size; i++) {
        cin >> price[i];

        if (i >= width)
            prices.erase(prices.find({ price[i - width], -(i - width) }));
        prices.insert({ price[i], -i });
        
        if (l <= -prices.begin()->second && -prices.begin()->second <= r)
            res[-prices.begin()->second - l]++;
    }

    for (int value : res)
        cout << value << "\t";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}