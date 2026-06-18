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

    int minPrice = 1e9, res = 0;
    for (int i = 0; i < size; i++) {
        int amount, price;
        cin >> amount >> price;

        minPrice = min(minPrice, price);
        res += amount * minPrice;
    }

    cout << res;
}