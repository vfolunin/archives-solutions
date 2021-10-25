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

    vector<int> factorials = { 1 };
    for (int i = 2; i < 10; i++)
        factorials.push_back(factorials.back() * i);

    int n;
    cin >> n;

    vector<int> minCount(n + 1, 1e9);
    minCount[0] = 0;

    for (int sum = 1; sum <= n; sum++)
        for (int f : factorials)
            if (f <= sum && minCount[sum] > minCount[sum - f] + 1)
                minCount[sum] = minCount[sum - f] + 1;

    cout << minCount[n] << "\n";
}