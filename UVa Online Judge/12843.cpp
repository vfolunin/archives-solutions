#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int area;
    cin >> area;
    area *= 2;

    vector<vector<int>> res;
    for (int a = 1; a * a <= area; a++) {
        if (area % a)
            continue;
        int b = area / a;
        int c = hypot(a, b);
        if (a * a + b * b == c * c)
            res.push_back({ a, b, c });
    }

    cout << "Case " << test << ": " << res.size() << "\n";
    for (vector<int> &r : res)
        cout << "(" << r[0] << "," << r[1] << "," << r[2] << ")\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}