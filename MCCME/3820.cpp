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

    int n;
    cin >> n;

    vector<int> price(7), count(7, 1);
    for (int i = 0; i < price.size(); i++) {
        cin >> price[i];
        if (i) {
            price[i] = min(price[i], price[i - 1] * 10);
            count[i] = count[i - 1] * 10;
        }
    }

    int res = 2e9 + 1;
    for (int i = 0; i < price.size(); i++)
        res = min(res, (n + count[i] - 1) / count[i] * price[i]);

    int sum = 0;
    for (int i = price.size() - 1; i >= 0; i--) {
        sum += n / count[i] * price[i];
        n %= count[i];
    }
    res = min(res, sum);

    cout << res;
}