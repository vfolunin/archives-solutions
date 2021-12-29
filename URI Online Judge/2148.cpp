#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double rec(int sum, int dieCount) {
    if (sum < 0)
        return 0;

    static vector<vector<double>> memo(81, vector<double>(14, -1));
    double &res = memo[sum][dieCount];
    if (res != -1)
        return res;

    if (dieCount == 0)
        return res = !sum;
    
    res = 0;
    for (int i = 1; i <= 6; i++)
        res += rec(sum - i, dieCount - 1) / 6;
    return res;
}

void solve() {
    int sum, dieCount;
    cin >> sum >> dieCount;

    cout.precision(15);
    cout << fixed << rec(sum, dieCount) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}