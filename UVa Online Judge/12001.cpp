#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long contestantCount, countryCount;
    cin >> contestantCount >> countryCount;

    if (!contestantCount && !countryCount)
        return 0;

    vector<long long> k(countryCount);
    for (int i = 0; i < contestantCount; i++) {
        int country;
        cin >> country;
        k[country - 1]++;
    }

    long long res3 = 0;
    for (int c = 0; c < countryCount; c++)
        res3 += k[c] * (k[c] - 1) * (k[c] - 2) / 6;
    for (int c1 = 0; c1 < countryCount; c1++)
        for (int c2 = c1 + 1; c2 < countryCount; c2++)
            for (int c3 = c2 + 1; c3 < countryCount; c3++)
                res3 += k[c1] * k[c2] * k[c3];

    long long res4 = 0;
    for (int c = 0; c < countryCount; c++) {
        res4 += k[c] * (k[c] - 1) * (k[c] - 2) * (k[c] - 3) / 24;
        res4 += k[c] * (k[c] - 1) * (k[c] - 2) / 6 * (contestantCount - k[c]);
    }
    for (int c1 = 0; c1 < countryCount; c1++) {
        for (int c2 = c1 + 1; c2 < countryCount; c2++) {
            for (int c3 = c2 + 1; c3 < countryCount; c3++) {
                res4 += k[c1] * (k[c1] - 1) / 2 * k[c2] * k[c3];
                res4 += k[c1] * k[c2] * (k[c2] - 1) / 2 * k[c3];
                res4 += k[c1] * k[c2] * k[c3] * (k[c3] - 1) / 2;
                for (int c4 = c3 + 1; c4 < countryCount; c4++)
                    res4 += k[c1] * k[c2] * k[c3] * k[c4];
            }
        }
    }

    cout << res3 << " " << res4 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}