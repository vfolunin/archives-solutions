#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int a, b;
    if (!(cin >> a >> b))
        return 0;
    b += a;

    set<double> xs;
    for (int i = 0; i < b; i++)
        xs.insert(1e4 / b * i);

    double res = 0;
    for (int i = 0; i < a; i++) {
        double x = 1e4 / a * i;
        auto it = xs.lower_bound(x);
        if (it == xs.end() || it != xs.begin() && *it - x > x - *prev(it))
            it--;
        res += abs(x - *it);
        xs.erase(x);
    }
    
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}