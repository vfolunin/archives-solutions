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

    vector<vector<int>> ways(targetSize + 1, vector<int>(targetSum + 1));
    for (int digit = 1; digit < 10 && digit <= targetSum; digit++)
        ways[1][digit] = 1;

    for (int size = 1; size < targetSize; size++)
        for (int sum = 0; sum <= targetSum; sum++)
            for (int digit = 0; digit < 10; digit++)
                if (sum + digit <= targetSum)
                    ways[size + 1][sum + digit] += ways[size][sum];

    cout << ways[targetSize][targetSum];
}