#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> maxPrice(30001, -1);
    maxPrice[0] = 0;

    for (int i = 0; i < n; i++) {
        int itemPrice, itemWeight;
        cin >> itemPrice >> itemWeight;
        for (int weight = maxPrice.size() - 1; weight >= itemWeight; weight--)
            if (maxPrice[weight - itemWeight] != -1)
                maxPrice[weight] = max(maxPrice[weight], maxPrice[weight - itemWeight] + itemPrice);
    }

    for (int weight = 1; weight < maxPrice.size(); weight++)
        maxPrice[weight] = max(maxPrice[weight], maxPrice[weight - 1]);

    int q;
    cin >> q;

    int res = 0;
    for (int i = 0; i < q; i++) {
        int weight;
        cin >> weight;
        res += maxPrice[weight];
    }
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}