#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> x(3), y(3);
    for (int i = 0; i < x.size(); i++)
        cin >> x[i] >> y[i];

    long long res = 0;
    for (int i = 0; i < x.size(); i++)
        res += gcd(abs(x[i] - x[(i + 1) % x.size()]), abs(y[i] - y[(i + 1) % y.size()]));

    cout << res;
}