#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <bitset>
using namespace std;

bool solve() {
    int aSize, bSize;
    if (!(cin >> aSize >> bSize))
        return 0;

    vector<int> nums(aSize + bSize);
    int sum = 0;
    for (int &n : nums) {
        cin >> n;
        sum += n;
    }

    vector<vector<bitset<5001>>> can(aSize + 1, vector<bitset<5001>>(nums.size() + 1));
    const int OFFSET = 2500;

    for (int numCount = 0; numCount <= nums.size(); numCount++)
        can[0][numCount][OFFSET] = 1;

    for (int subsetSize = 1; subsetSize <= aSize; subsetSize++) {
        for (int numCount = 1; numCount <= nums.size(); numCount++) {
            int n = nums[numCount - 1];
            for (int sum = 0; sum <= 5000; sum++)
                can[subsetSize][numCount][sum] = can[subsetSize][numCount - 1][sum] | (sum >= n && can[subsetSize - 1][numCount - 1][sum - n]);
        }
    }

    int minRes = 1e9, maxRes = -1e9;
    for (int i = 0; i < 5001; i++) {
        int sa = i - OFFSET, sb = sum - sa;
        if (can[aSize][nums.size()][i]) {
            minRes = min(minRes, sa * sb);
            maxRes = max(maxRes, sa * sb);
        }
    }

    cout << maxRes << " " << minRes << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}