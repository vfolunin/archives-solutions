#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitProduct(int n) {
    int product = 1;
    while (n) {
        product *= n % 10;
        n /= 10;
    }
    return product;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, target;
    cin >> size >> target;

    int res, resDiff = 1e9;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        int diff = abs(digitProduct(value) - target);
        if (resDiff > diff) {
            resDiff = diff;
            res = value;
        }
    }

    cout << res;
}