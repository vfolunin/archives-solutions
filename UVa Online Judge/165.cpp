#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    int countLimit, stampLimit;
    vector<int> stamps, bestStamps;
    int mex, bestMex;

    Solver() {
        cin >> countLimit >> stampLimit;
        bestMex = 1;
    }

    int getMex() {
        vector<vector<int>> can(countLimit + 1, vector<int>(100));
        can[0][0] = 1;
        for (int count = 1; count <= countLimit; count++) {
            for (int sum = 0; sum < 100; sum++) {
                can[count][sum] = can[count - 1][sum];
                for (int stamp : stamps)
                    if (stamp <= sum)
                        can[count][sum] |= can[count - 1][sum - stamp];
            }
        }
        return find(can.back().begin(), can.back().end(), 0) - can.back().begin();
    }

    void rec() {
        int mex = getMex();

        if (stamps.size() == stampLimit) {
            if (bestMex < mex) {
                bestMex = mex;
                bestStamps = stamps;
            }
            return;
        }

        bestMex = max(bestMex, mex);

        for (int stamp = (stamps.empty() ? 1 : stamps.back() + 1); stamp <= mex; stamp++) {
            stamps.push_back(stamp);
            rec();
            stamps.pop_back();
        }
    }
};

bool solve() {
    Solver solver;
    if (!solver.countLimit)
        return 0;

    solver.rec();

    for (int stamp : solver.bestStamps)
        cout << setw(3) << stamp;
    cout << " ->" << setw(3) << solver.bestMex - 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}