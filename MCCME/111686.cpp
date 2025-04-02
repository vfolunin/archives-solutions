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

    int res, resCount = 1e9;

    for (int y = 0; y < 9; y++) {
        int count = 0;

        for (int x = 0; x < 10; x++) {
            int value;
            cin >> value;

            count += value % 2 != 0;
        }

        if (resCount >= count) {
            resCount = count;
            res = y + 1;
        }
    }

    cout << res;
}