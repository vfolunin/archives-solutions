#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool canWin(map<string, vector<int>> &medals, const vector<double> &weights) {
    map<string, double> score;
    double maxScore = 0;

    for (auto &[country, m] : medals) {
        score[country] = m[0] * weights[0] + m[1] * weights[1] + m[2] * weights[2];
        maxScore = max(maxScore, score[country]);
    }

    return score["Canada"] == maxScore;
}

bool solve() {
    int countryCount;
    cin >> countryCount;

    if (!countryCount)
        return 0;

    map<string, vector<int>> medals;
    for (int i = 0; i < countryCount; i++) {
        string country;
        int a, b, c;
        cin >> country >> a >> b >> c;
        medals[country] = { a, b, c };
    }

    for (int ap = 0; ap >= -10; ap--) {
        for (int bp = 0; bp >= -10; bp--) {
            for (int cp = 0; cp >= -10; cp--) {
                if (canWin(medals, { pow(10, ap), pow(10, bp), pow(10, cp) })) {
                    cout << "Canada wins!\n";
                    return 1;
                }
            }
        }
    }

    cout << "Canada cannot win.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}