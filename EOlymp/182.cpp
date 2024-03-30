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

    int size, aThreshold, bThreshold;
    cin >> size >> aThreshold >> bThreshold;

    vector<int> maxSum(size + 1, -1e9);
    maxSum[0] = 0;

    for (int i = 0; i < size; i++) {
        int a, b;
        cin >> a >> b;

        vector<int> nextMaxSum(size + 1, -1e9);
        for (int aCount = 0; aCount <= size; aCount++) {
            if (aCount && maxSum[aCount - 1] != -1e9)
                nextMaxSum[aCount] = max(nextMaxSum[aCount], maxSum[aCount - 1] + a);
            if (maxSum[aCount] != -1e9)
                nextMaxSum[aCount] = max(nextMaxSum[aCount], maxSum[aCount] + b);
        }
        maxSum.swap(nextMaxSum);
    }

    int res = -1;
    for (int aCount = aThreshold, bCount = size - aCount; bCount >= bThreshold; aCount++, bCount--)
        res = max(res, maxSum[aCount]);

    cout << res;
}