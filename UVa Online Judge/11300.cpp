#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int personCount;
    if (!(cin >> personCount))
        return 0;

    vector<long long> coinsBefore(personCount);
    long long coinsAfter = 0;
    for (long long &coins : coinsBefore) {
        cin >> coins;
        coinsAfter += coins;
    }
    coinsAfter /= personCount;

    vector<long long> pDiff(personCount);
    for (int i = 0; i < personCount; i++) {
        pDiff[i] = coinsBefore[i] - coinsAfter;
        if (i)
            pDiff[i] += pDiff[i - 1];
    }

    nth_element(pDiff.begin(), pDiff.begin() + personCount / 2, pDiff.end());
    long long medianPDiff = pDiff[personCount / 2];

    long long res = 0;
    for (long long diff : pDiff)
        res += abs(diff - medianPDiff);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}