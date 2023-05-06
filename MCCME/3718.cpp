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

    int targetSum;
    cin >> targetSum;

    vector<long long> res(targetSum + 1, 1e18);
    res[0] = 0;
    res[1] = 1;
    
    for (int sum = 2; sum <= targetSum; sum++)
        for (int i = 1; i < 10 && i * i * i <= sum; i++)
            res[sum] = min(res[sum], res[sum - i * i * i] * 10 + i);
    
    cout << res[targetSum];
}