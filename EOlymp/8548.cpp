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

    int size, mod;
    cin >> size >> mod;

    vector<int> count(mod);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        count[value % mod]++;
    }

    int res = count[0] * (count[0] - 1) / 2;
    for (int a = 1, b = mod - 1; a <= b; a++, b--) {
        if (a < b)
            res += count[a] * count[b];
        else
            res += count[a] * (count[a] - 1) / 2;
    }

    cout << res;
}