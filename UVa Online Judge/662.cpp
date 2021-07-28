#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void print(int r, int k, vector<vector<int>> &depotPosIndex, vector<vector<int>> &from) {
    if (!k)
        return;
    int l = from[r][k];
    print(l - 1, k - 1, depotPosIndex, from);
    cout << "Depot " << k << " at restaurant " << depotPosIndex[l][r] + 1 << " serves restaurant";
    if (l == r)
        cout << " " << l + 1 << "\n";
    else
        cout << "s " << l + 1 << " to " << r + 1 << "\n";
}

bool solve(int test) {
    int cafeCount, depotCount;
    cin >> cafeCount >> depotCount;

    if (!cafeCount)
        return 0;

    vector<int> cafePos(cafeCount);
    for (int &x : cafePos)
        cin >> x;

    vector<vector<int>> dist(cafeCount, vector<int>(cafeCount));
    vector<vector<int>> depotPosIndex(cafeCount, vector<int>(cafeCount));

    for (int i = 0; i < cafeCount; i++)
        depotPosIndex[i][i] = i;

    for (int len = 2; len <= cafeCount; len++) {
        for (int l = 0, r = len - 1; r < cafeCount; l++, r++) {
            depotPosIndex[l][r] = depotPosIndex[l][r - 1] + len % 2;
            for (int i = l; i <= r; i++)
                dist[l][r] += abs(cafePos[i] - cafePos[depotPosIndex[l][r]]);
        }
    }

    vector<vector<int>> res(cafeCount, vector<int>(depotCount + 1, 1e9));
    vector<vector<int>> from(cafeCount, vector<int>(depotCount + 1));

    for (int r = 0; r < cafeCount; r++) {
        res[r][1] = dist[0][r];
        from[r][1] = 0;
    }

    for (int r = 1; r < cafeCount; r++) {
        for (int k = 2; k <= depotCount; k++) {
            for (int l = 1; l <= r; l++) {
                if (res[r][k] > res[l - 1][k - 1] + dist[l][r]) {
                    res[r][k] = res[l - 1][k - 1] + dist[l][r];
                    from[r][k] = l;
                }
            }
        }
    }

    cout << "Chain " << test << "\n";
    print(cafeCount - 1, depotCount, depotPosIndex, from);
    cout << "Total distance sum = " << res[cafeCount - 1][depotCount] << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}