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

    vector<vector<long double>> p(2, vector<long double>(max(targetSum + 1, 7)));
    p[0][0] = 1;

    for (int size = 1; size <= targetSize; size++) {
        fill(p[1].begin(), p[1].end(), 0);

        for (int sum = targetSum; sum >= 0; sum--)
            for (int digit = 1; digit <= 6 && digit <= sum; digit++)
                p[1][sum] += p[0][sum - digit] / 6.0;

        p[0].swap(p[1]);
    }

    cout << p[0][targetSum];
}