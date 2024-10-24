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

    int n;
    cin >> n;

    double res = 0;
    for (int i = 1; i <= n && i < 2e6; i++)
        res += 1.0 / (1.0 * i * i);

    cout << fixed << res;
}