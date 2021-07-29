#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    vector<vector<int>> resType;
    vector<vector<long long>> resEnergy;
    vector<int> objCount;
    int totalCount = 0;
    map<vector<int>, long long> memo;

    Solver(int size) {
        resType.assign(size, vector<int>(size));
        resEnergy.assign(size, vector<long long>(size));
        objCount.resize(size);
    }

    long long rec() {
        if (memo.count(objCount))
            return memo[objCount];

        if (totalCount <= 1)
            return memo[objCount] = 0;

        long long minEnergy = 1LL << 60;

        for (int i = 0; i < objCount.size(); i++) {
            if (!objCount[i])
                continue;
            objCount[i]--;
            totalCount--;

            for (int j = 0; j < objCount.size(); j++) {
                if (!objCount[j])
                    continue;
                objCount[j]--;

                objCount[resType[i][j]]++;
                minEnergy = min(minEnergy, resEnergy[i][j] + rec());
                objCount[resType[i][j]]--;

                objCount[j]++;
            }

            objCount[i]++;
            totalCount++;
        }

        return memo[objCount] = minEnergy;
    }
};

void solve() {
    int typeCount;
    cin >> typeCount;

    Solver solver(typeCount);

    for (int i = 0; i < typeCount; i++) {
        for (int j = 0; j < typeCount; j++) {
            cin >> solver.resType[i][j] >> solver.resEnergy[i][j];
            solver.resType[i][j]--;
        }
    }

    int objectCount;
    cin >> objectCount;

    for (int i = 0; i < objectCount; i++) {
        int type;
        cin >> type;
        solver.objCount[type - 1]++;
        solver.totalCount++;
    }

    char c;
    cin >> c;

    cout << solver.rec() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}