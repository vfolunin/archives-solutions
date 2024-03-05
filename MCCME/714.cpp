#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int teamCount;
    cin >> teamCount;

    vector<pair<int, int>> teams(teamCount);
    for (int i = 0; i < teams.size(); i++) {
        cin >> teams[i].first;
        teams[i].second = i;
    }

    vector<vector<int>> res(teams.size(), vector<int>(teams.size()));

    while (!teams.empty()) {
        sort(teams.begin(), teams.end());
        auto [aScore, aIndex] = *teams.begin();
        teams.erase(teams.begin());

        for (auto &[bScore, bIndex] : teams) {
            if (aScore) {
                aScore--;
                bScore--;
                res[aIndex][bIndex] = res[bIndex][aIndex] = 1;
            } else {
                bScore -= 2;
                res[bIndex][aIndex] = 2;
            }
        }
    }

    for (int aIndex = 0; aIndex < res.size(); aIndex++) {
        for (int bIndex = 0; bIndex < res.size(); bIndex++)
            cout << res[aIndex][bIndex] << " ";
        cout << "\n";
    }
}