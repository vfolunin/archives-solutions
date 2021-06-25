#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<double> getH() {
    vector<double> h(1001);
    for (int i = 1; i < h.size(); i++)
        h[i] = h[i - 1] + 1.0 / i;
    return h;
}

void solve(int test) {
    int n;
    cin >> n;

    static vector<double> h = getH();
    double p = 1 - (h[n] - h[n / 2]);

    cout.precision(8);
    cout << "Case #" << test << ": " << fixed << p << " " << 1 / p << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}