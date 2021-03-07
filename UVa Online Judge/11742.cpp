#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int personCount, constraintCount;
    cin >> personCount >> constraintCount;

    if (!personCount && !constraintCount)
        return 0;

    vector<vector<int>> constraint(constraintCount, vector<int>(3));
    for (vector<int> &c : constraint)
        cin >> c[0] >> c[1] >> c[2];

    vector<int> p;
    for (int i = 0; i < personCount; i++)
        p.push_back(i);

    int res = 0;
    do {
        bool ok = 1;
        for (int i = 0; ok && i < constraintCount; i++) {
            int aPos = find(p.begin(), p.end(), constraint[i][0]) - p.begin();
            int bPos = find(p.begin(), p.end(), constraint[i][1]) - p.begin();
            int dist = abs(aPos - bPos);
            ok &= constraint[i][2] > 0 && dist <= constraint[i][2] ||
                  constraint[i][2] < 0 && dist >= -constraint[i][2];
        }
        res += ok;
    } while (next_permutation(p.begin(), p.end()));

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}