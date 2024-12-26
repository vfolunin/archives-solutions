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

    int targetCount, targetSum;
    cin >> targetCount >> targetSum;

    vector<vector<long long>> ways(targetCount + 1, vector<long long>(targetSum + 1));
    ways[0][0] = 1;

    for (int count = 1; count <= targetCount; count++)
        for (int sum = 0; sum <= targetSum; sum++)
            for (int last = 0; last <= sum; last++)
                ways[count][sum] += ways[count - 1][sum - last];

    cout << ways[targetCount][targetSum];
}