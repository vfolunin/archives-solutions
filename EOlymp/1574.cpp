#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

bool solve() {
    int n, minSum;
    cin >> n >> minSum;

    if (!n && !minSum)
        return 0;

    vector<vector<long long>> ways(2, vector<long long>(150));
    ways[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int sum = 0; sum < 150; sum++) {
            if (ways[0][sum])
                for (int nextSum = sum + 1; nextSum <= sum + 6; nextSum++)
                    ways[1][nextSum] += ways[0][sum];
        }

        for (int sum = 0; sum < 150; sum++) {
            ways[0][sum] = ways[1][sum];
            ways[1][sum] = 0;
        }
    }

    long long num = 0;
    for (int sum = minSum; sum < 150; sum++)
        num += ways[0][sum];

    long long den = 1;
    for (int i = 0; i < n; i++)
        den *= 6;

    long long g = gcd(num, den);
    num /= g;
    den /= g;

    cout << num;
    if (den != 1)
        cout << "/" << den;
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}