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

    int size;
    cin >> size;

    vector<int> price(size), count(size);
    for (int i = 0; i < size; i++)
        cin >> price[i] >> count[i];

    for (int i = size - 2; i >= 0; i--)
        price[i] = max(price[i], price[i + 1]);

    long long res = 0;
    for (int i = 0; i < size; i++)
        res += 1LL * price[i] * count[i];

    cout << res;
}