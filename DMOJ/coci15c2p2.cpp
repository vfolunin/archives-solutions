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

    int ingredientCount, pairCount;
    cin >> ingredientCount >> pairCount;

    vector<int> pairMasks(pairCount);
    for (int &pairMask : pairMasks) {
        int a, b;
        cin >> a >> b;
        pairMask |= 1 << (a - 1);
        pairMask |= 1 << (b - 1);
    }

    int res = 0;
    for (int mask = 0; mask < (1 << ingredientCount); mask++) {
        bool ok = 1;
        for (int pairMask : pairMasks) {
            if ((mask & pairMask) == pairMask) {
                ok = 0;
                break;
            }
        }
        res += ok;
    }

    cout << res;
}