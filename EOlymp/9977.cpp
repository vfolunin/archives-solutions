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
    for (int i = 1; i <= n; i++)
        res += (i * 2 - 1.0) / (i * 2);

    cout << fixed << res;
}