#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<double> prepare() {
    vector<double> res = { 0, 0.5 };
    for (int i = 2; i < 1e6; i++)
        res.push_back(res.back() + 0.5 / i);
    return res;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<double> res = prepare();

    cout << setw(5) << n << setw(10) << setprecision(3) << fixed << res[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout << "# Cards Overhang\n";
    while (solve());
}