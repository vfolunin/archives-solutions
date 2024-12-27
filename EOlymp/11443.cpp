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

    int n;
    double x;
    cin >> n >> x;

    double p = x, res = 0;
    for (int i = 0; i < n; i++) {
        res += sin(p);
        p *= x;
    }

    cout << fixed << res;
}