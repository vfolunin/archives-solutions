#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double a, b, c;
    cin >> a >> b >> c;

    double x = -b / (2 * a);

    cout.precision(2);
    cout << fixed << a * x * x + b * x + c << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}