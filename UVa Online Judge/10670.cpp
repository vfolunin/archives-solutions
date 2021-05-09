#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Agency {
    string name;
    int a, b, cost;

    bool operator < (const Agency &that) const {
        if (cost != that.cost)
            return cost < that.cost;
        return name < that.name;
    }
};

void solve(int test) {
    int startLoad, endLoad, agencyCount;
    scanf("%d%d%d", &startLoad, &endLoad, &agencyCount);

    vector<Agency> agencies(agencyCount);
    for (auto &[name, a, b, cost] : agencies) {
        char buf[20];
        scanf(" %[^:]:%d,%d", buf, &a, &b);
        name = buf;
        cost = 1e9;
    }

    for (auto &[_, a, b, cost] : agencies)
        for (int bCount = 0, load = startLoad; load >= endLoad && load; bCount++, load /= 2)
            cost = min(cost, bCount * b + (load - endLoad) * a);

    sort(agencies.begin(), agencies.end());

    printf("Case %d\n", test);
    for (auto &[name, a, b, ops] : agencies)
        printf("%s %d\n", name.c_str(), ops);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int test = 1; test <= n; test++)
        solve(test);
}