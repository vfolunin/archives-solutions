#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<long long> &population, long long populationPerBox, long long boxCount) {
    long long boxNeed = 0;
    for (long long &p : population)
        boxNeed += (p + populationPerBox - 1) / populationPerBox;
    return boxNeed <= boxCount;
}

bool solve() {
    long long cityCount, boxCount;
    cin >> cityCount >> boxCount;

    if (cityCount < 0)
        return 0;

    vector<long long> population(cityCount);
    for (long long &p : population)
        cin >> p;

    long long l = 0, r = *max_element(population.begin(), population.end());
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(population, m, boxCount))
            r = m;
        else
            l = m;
    }

    cout << r << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}