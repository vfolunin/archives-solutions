#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<long long> res = { 1, 1, 1 };
    for (int i = 3; i <= 75; i++)
        res.push_back(res[i - 2] + res[i - 3]);
    return res;
}

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    static vector<long long> res = prepare();

    cout << res[size] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}