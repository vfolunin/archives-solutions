#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(vector<int> &powers, int limit, int target) {
    if (powers.size() > limit)
        return powers.back() == target;
    
    if (powers.back() > target)
        return 0;
    if (powers.back() * (1 << (limit - powers.size() + 1)) < target)
        return 0;
    
    for (int i = powers.size() - 1; i >= 0; i--) {
        powers.push_back(powers[i] + powers.back());
        if (rec(powers, limit, target))
            return 1;
        powers.pop_back();
    }

    return 0;
}

int getL(int n) {
    if (n == 1)
        return 0;
    return getL(n / 2) + 1;
}

int solve(int target) {
    vector<int> powers = { 1 };
    powers.reserve(20);
    int limit = getL(target);
    while (!rec(powers, limit, target))
        limit++;
    return limit;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int target;
    cin >> target;

    cout << solve(target);
}