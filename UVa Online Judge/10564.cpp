#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size, sum;
    cin >> size >> sum;

    if (!size && !sum)
        return 0;

    vector<vector<int>> a;
    for (int i = size; i >= 1; i--)
        a.push_back(vector<int>(i));
    for (int i = 2; i <= size; i++)
        a.push_back(vector<int>(i));

    for (vector<int> &row : a)
        for (int &x : row)
            cin >> x;

    vector<vector<vector<long long>>> pathCount(a.size(), vector<vector<long long>>(a.size(), vector<long long>(sum + 1, 0)));
    vector<vector<vector<string>>> minPath(a.size(), vector<vector<string>>(a.size(), vector<string>(sum + 1, "z")));

    for (int j = 0; j < size; j++) {
        pathCount[0][j][a[0][j]] = 1;
        minPath[0][j][a[0][j]] = string(1, 'a' + j);
    }

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            for (int s = a[i][j]; s <= sum; s++) {

                if (pathCount[i - 1][j][s - a[i][j]]) {
                    pathCount[i][j][s] += pathCount[i - 1][j][s - a[i][j]];
                    minPath[i][j][s] = min(minPath[i][j][s], minPath[i - 1][j][s - a[i][j]] + 'R');
                }

                if (pathCount[i - 1][j + 1][s - a[i][j]]) {
                    pathCount[i][j][s] += pathCount[i - 1][j + 1][s - a[i][j]];
                    minPath[i][j][s] = min(minPath[i][j][s], minPath[i - 1][j + 1][s - a[i][j]] + 'L');
                }

            }
        }
    }

    for (int i = size; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            for (int s = a[i][j]; s <= sum; s++) {

                if (pathCount[i - 1][j][s - a[i][j]]) {
                    pathCount[i][j][s] += pathCount[i - 1][j][s - a[i][j]];
                    minPath[i][j][s] = min(minPath[i][j][s], minPath[i - 1][j][s - a[i][j]] + 'L');
                }

                if (j && pathCount[i - 1][j - 1][s - a[i][j]]) {
                    pathCount[i][j][s] += pathCount[i - 1][j - 1][s - a[i][j]];
                    minPath[i][j][s] = min(minPath[i][j][s], minPath[i - 1][j - 1][s - a[i][j]] + 'R');
                }

            }
        }
    }

    long long resPathCount = 0;
    string resPath = "z";

    for (int j = 0; j < size; j++) {
        if (pathCount.back()[j][sum]) {
            resPathCount += pathCount.back()[j][sum];
            resPath = min(resPath, minPath.back()[j][sum]);
        }
    }

    cout << resPathCount << "\n";
    if (resPathCount)
        cout << resPath[0] - 'a' << " " << resPath.substr(1) << "\n";
    else
        cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}