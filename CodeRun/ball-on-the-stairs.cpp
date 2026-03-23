#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<long long> res = { 1, 1, 2, 4 };
    for (int i = 4; i <= n; i++)
        res.push_back(res[i - 1] + res[i - 2] + res[i - 3]);

    cout << res[n];
}