#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double rec(int chocolates, int boxesWithChocolate, int boxes, vector<vector<double>> &memo) {
    double &res = memo[chocolates][boxesWithChocolate];
    if (res != -1)
        return res;

    if (!chocolates || !boxesWithChocolate)
        return res = !chocolates && !boxesWithChocolate;

    res = 0;
    res += rec(chocolates - 1, boxesWithChocolate, boxes, memo) * boxesWithChocolate / boxes;
    res += rec(chocolates - 1, boxesWithChocolate - 1, boxes, memo) * (boxes - boxesWithChocolate + 1) / boxes;
    return res;
}

bool solve(int test) {
    int chocolates, boxes;
    if (!(cin >> chocolates >> boxes))
        return 0;

    vector<vector<double>> memo(chocolates + 1, vector<double>(boxes + 1, -1));
    double res = 1 - rec(chocolates, boxes, boxes, memo);

    cout.precision(7);
    cout << "Case " << test << ": " << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}