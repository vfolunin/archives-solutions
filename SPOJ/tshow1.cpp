#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long index;
    cin >> index;

    vector<int> digits = { 5, 6 };

    vector<long long> powers = { 1 };
    while (index >= powers.back()) {
        index -= powers.back();
        powers.push_back(powers.back() * digits.size());
    }

    for (int i = powers.size() - 2; i >= 0; i--) {
        cout << digits[index / powers[i]];
        index %= powers[i];
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}