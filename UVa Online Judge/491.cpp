#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<long long> res = {
        0, 1, 1, 2, 7,
        18, 60, 196, 704, 2500,
        9189, 33896, 126759, 476270, 1802312,
        6849777, 26152418, 100203194, 385221143, 1485200848
    };

    cout << res[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}