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

    int res, resProduct = 0;

    for (int y = 0; y < 10; y++) {
        int product = 1;

        for (int x = 0; x < 9; x++) {
            int value;
            cin >> value;

            if (value % 2 == 0)
                product *= value;
        }

        if (resProduct < product) {
            resProduct = product;
            res = y + 1;
        }
    }

    cout << res;
}