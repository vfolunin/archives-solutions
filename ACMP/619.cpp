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

    vector<vector<double>> p(targetSize + 1, vector<double>(max(targetSum + 1, 7)));
    fill(p[1].begin() + 1, p[1].begin() + 7, 1 / 6.0);

    for (int size = 2; size <= targetSize; size++)
        for (int sum = targetSum; sum >= 0; sum--)
            for (int digit = 1; digit <= 6 && digit <= sum; digit++)
                p[size][sum] += p[size - 1][sum - digit] / 6.0;

    cout << p[targetSize][targetSum];
}