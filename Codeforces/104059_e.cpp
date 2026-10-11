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

    long long n;
    cin >> n;

    vector<double> res = { 1, 0, 0.5 };
    for (int i = 3; i < n && i < 100; i++) {
        res[0] = res[1];
        res[1] = res[2];
        res[2] = (res[0] + res[1]) / 2;
    }

    cout << fixed << 100 * res[min(n - 1, 2LL)] << " " << 100 * (1 - res[min(n - 1, 2LL)]);
}