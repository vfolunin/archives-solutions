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

    vector<vector<int>> ways(10, vector<int>(targetSum + 1));
    for (int digit = 1; digit < 10 && digit <= targetSum; digit++)
        ways[1][digit] = 1;

    for (int size = 1; size + 1 < ways.size(); size++)
        for (int sum = 0; sum <= targetSum; sum++)
            for (int digit = 0; digit < 10; digit++)
                if (sum + digit <= targetSum)
                    ways[size + 1][sum + digit] += ways[size][sum];

    int res = targetSum == 1;
    for (int size = 1; size < ways.size(); size++)
        res += ways[size][targetSum];

    cout << res;
}