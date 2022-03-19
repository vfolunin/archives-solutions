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

    int mul = 1, res = 0;

    for (int mod : { 2, 3, 5, 7, 11, 13, 17, 19 }) {
        int x;
        cin >> x;

        res += (mod - 1 - x) * mul;
        mul *= mod;
    }

    cout << res;
}