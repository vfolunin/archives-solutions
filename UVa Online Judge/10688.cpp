#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int appleCount, int minWeight) {
    static vector<vector<int>> memo(600, vector<int>(600, -1));
    int &res = memo[appleCount][minWeight];
    if (res != -1)
        return res;

    if (appleCount <= 1)
        return res = 0;
    if (appleCount == 2)
        return res = 2 * minWeight;

    res = 1e9;
    for (int i = 0, weight = minWeight; i < appleCount; i++, weight++) {
        int less = i * weight + rec(i, minWeight);
        int equal = weight;
        int greater = (appleCount - 1 - i) * weight + rec(appleCount - 1 - i, weight + 1);
        res = min(res, less + equal + greater);
    }
    return res;
}

void solve(int test) {
    int appleCount, minWeight;
    cin >> appleCount >> minWeight;
    minWeight++;

    cout << "Case " << test << ": " << rec(appleCount, minWeight) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}