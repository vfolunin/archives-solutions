#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isComposite(int n) {
    if (n < 2)
        return 0;

    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 1;

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long targetSum;
    cin >> targetSum;

    vector<int> maxCount(min(100LL, targetSum + 1), -1);
    maxCount[0] = 0;
    
    for (int sum = 1; sum < maxCount.size(); sum++)
        for (int part = 1; part <= sum; part++)
            if (isComposite(part) && maxCount[sum - part] != -1)
                maxCount[sum] = max(maxCount[sum], maxCount[sum - part] + 1);
    
    long long res = -1;
    for (int part = 0; part < maxCount.size(); part++)
        if (maxCount[part] != -1 && (targetSum - part) % 4 == 0)
            res = max(res, maxCount[part] + (targetSum - part) / 4);

    cout << res;
}