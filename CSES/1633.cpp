#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<long long> ways(1e6 + 1);
    ways[0] = 1;

    for (int sum = 1; sum < ways.size(); sum++)
        for (int last = 1; last <= 6 && last <= sum; last++)
            ways[sum] = (ways[sum] + ways[sum - last]) % MOD;
    
    int n;
    cin >> n;
    cout << ways[n];
}