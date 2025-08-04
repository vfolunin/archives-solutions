#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double playerCount, prizeCount;
    cin >> playerCount >> prizeCount;

    int limit = playerCount / (prizeCount - 1);
    double res = (limit * prizeCount) / (playerCount + 1);
    for (int i = 2; i <= limit; ++i)
        res *= (playerCount - prizeCount + i) / (playerCount + i);

    cout << fixed << res;
}