#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int h, w;
    cin >> h >> w;

    vector<int> res(w);
    bool fail = 0;

    for (int i = 0; i < h; i++) {
        string row;
        cin >> row;

        vector<int> zeroPos;
        for (int j = 0; j < w; j++)
            if (row[j] == '0')
                zeroPos.push_back(j);
    
        for (int j = 0; j < w; j++) {
            int minZeroDist = 1e9;
            int posIndex = lower_bound(zeroPos.begin(), zeroPos.end(), j) - zeroPos.begin();
            if (posIndex != zeroPos.size())
                minZeroDist = min(minZeroDist, zeroPos[posIndex] - j);
            if (posIndex != 0)
                minZeroDist = min(minZeroDist, j - zeroPos[posIndex - 1]);
            if (minZeroDist == 1e9)
                fail = 1;
            else
                res[j] += minZeroDist;
        }
    }

    cout << "Case " << test << ": " << (fail ? -1 : *min_element(res.begin(), res.end())) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}