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

    int targetSize, targetSum;
    cin >> targetSize >> targetSum;

    vector<vector<long long>> count(targetSize + 1, vector<long long>(max(targetSum + 1, 10)));
    fill(count[1].begin(), count[1].begin() + 10, 1);

    for (int size = 2; size <= targetSize; size++)
        for (int sum = targetSum; sum >= 0; sum--)
            for (int digit = 0; digit <= 9 && digit <= sum; digit++)
                count[size][sum] += count[size - 1][sum - digit];

    cout << count[targetSize][targetSum];
}