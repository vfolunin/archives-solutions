#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, targetSum;
    cin >> size >> targetSum;

    unordered_map<int, int> seen;
    int sum = 0;
    seen[sum] = 1;

    long long res = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
        if (seen.count(sum - targetSum))
            res += seen[sum - targetSum];
        seen[sum]++;
    }

    cout << res;
}