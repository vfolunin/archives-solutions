#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, x;
    cin >> n >> x;

    double res = 0;
    for (int i = n; i; i--)
        res = sqrt(i * x + res);

    cout << fixed << res;
}