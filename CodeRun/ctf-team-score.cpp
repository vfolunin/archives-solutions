#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_map<int, vector<vector<int>>> solutions;
    for (int team = 0; team < 2; team++) {
        int solutionCount;
        cin >> solutionCount;

        for (int i = 0; i < solutionCount; i++) {
            int problem, time;
            cin >> problem >> time;

            solutions[problem].resize(2);
            solutions[problem][team].push_back(time);
        }
    }

    vector<int> res(2);
    for (auto [_, solutions] : solutions) {
        sort(solutions[0].begin(), solutions[0].end());
        sort(solutions[1].begin(), solutions[1].end());

        if (solutions[0].empty())
            res[1] += solutions[1].size();
        else if (solutions[1].empty())
            res[0] += solutions[0].size();
        else if (solutions[0][0] < solutions[1][0])
            res[0] += lower_bound(solutions[0].begin(), solutions[0].end(), solutions[1][0]) - solutions[0].begin();
        else
            res[1] += lower_bound(solutions[1].begin(), solutions[1].end(), solutions[0][0]) - solutions[1].begin();
    }

    cout << res[0] << " " << res[1];
}