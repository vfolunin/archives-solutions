#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int levelCount = 4;
    int teamCount = 1 << levelCount;

    vector<string> teamName(teamCount);
    for (string &name : teamName)
        cin >> name;

    vector<vector<double>> winP(teamCount, vector<double>(teamCount));
    for (vector<double> &row : winP) {
        for (double &p : row) {
            cin >> p;
            p /= 100;
        }
    }

    vector<vector<double>> levelP(levelCount, vector<double>(teamCount));
    for (int t1 = 0; t1 < teamCount; t1++)
        levelP[0][t1] = winP[t1][t1 ^ 1];
    for (int level = 1; level < levelCount; level++) {
        for (int t1 = 0; t1 < teamCount; t1++) {
            int t2l = ((t1 >> level) ^ 1) << level;
            int t2r = t2l + (1 << level);
            for (int t2 = t2l; t2 < t2r; t2++)
                levelP[level][t1] += levelP[level - 1][t1] * levelP[level - 1][t2] * winP[t1][t2];
        }
    }

    for (int i = 0; i < teamCount; i++) {
        cout << setw(10) << left << teamName[i];
        cout << " p=" << fixed << setprecision(2) << levelP[levelCount - 1][i] * 100 << "%\n";
    }
}