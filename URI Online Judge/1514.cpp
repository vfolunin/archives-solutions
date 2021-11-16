#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int userCount, problemCount;
    cin >> userCount >> problemCount;

    if (!userCount && !problemCount)
        return 0;

    vector<int> userScore(userCount), problemScore(problemCount);
    for (int u = 0; u < userCount; u++) {
        for (int p = 0; p < problemCount; p++) {
            int solved;
            cin >> solved;
            userScore[u] += solved;
            problemScore[p] += solved;
        }
    }

    int res = 0;
    res += *min_element(userScore.begin(), userScore.end()) > 0;
    res += *max_element(userScore.begin(), userScore.end()) < problemCount;
    res += *min_element(problemScore.begin(), problemScore.end()) > 0;
    res += *max_element(problemScore.begin(), problemScore.end()) < userCount;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}