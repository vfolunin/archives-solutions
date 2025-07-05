#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double value;
    cin >> value;

    stringstream ss;
    ss.precision(20);
    ss << fixed << cbrt(value);
    
    string res = ss.str();
    res = res.substr(0, res.find('.') + 5);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}