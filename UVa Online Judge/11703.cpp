#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> res(1000001);
    res[0] = 1;
    for (int i = 1; i < res.size(); i++)
        res[i] = (res[i - sqrt(i)] + res[log(i)] + res[i * sin(i) * sin(i)]) % 1000000;
    return res;
}

bool solve() {
    int n;
    cin >> n;

    if (n == -1)
        return 0;

    static vector<int> res = prepare();

    cout << res[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}