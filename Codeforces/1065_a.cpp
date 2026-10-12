#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long money, threshold, bonus, price;
    cin >> money >> threshold >> bonus >> price;

    long long itemCount = money / price;
    long long bonusCount = itemCount / threshold;

    cout << itemCount + bonusCount * bonus << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}