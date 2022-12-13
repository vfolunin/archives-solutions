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

    int playerCount, maxLevel, mod;
    cin >> playerCount >> maxLevel >> mod;

    int res = maxLevel / mod * playerCount;
    res += min(maxLevel, mod - 1) * playerCount;

    cout << res;
}