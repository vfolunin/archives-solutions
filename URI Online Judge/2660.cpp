#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int populationCount;
    long long limit, period;
    cin >> populationCount >> limit >> period;

    for (int i = 1; i < populationCount; i++) {
        int p;
        cin >> p;
        period = lcm(period, p);
    }

    int res = 1, resPeriod = period;
    for (int p = 2; p <= limit; p++) {
        int curPeriod = lcm(period, p);
        if (curPeriod <= limit && resPeriod < curPeriod) {
            resPeriod = curPeriod;
            res = p;
        }
    }

    cout << res << "\n";
}