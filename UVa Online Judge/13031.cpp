#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int generatorTypeCount;
    cin >> generatorTypeCount;

    vector<pair<long long, long long>> generators(generatorTypeCount);
    for (auto &[power, count] : generators)
        cin >> count >> power;

    sort(generators.begin(), generators.end());
    for (int i = generatorTypeCount - 2; i >= 0; i--)
        generators[i].second += generators[i + 1].second;

    long long res = 0;
    for (auto &[power, count] : generators)
        res = max(res, power * count);

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}