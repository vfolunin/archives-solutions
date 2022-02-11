#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long population, factor, foodProduction;
    cin >> population >> factor >> foodProduction;

    int years = 0;
    while (population <= foodProduction) {
        population *= factor;
        years++;
    }

    cout << years << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}