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

    vector<long long> res = { 0, 1, 1 };
    for (int i = 3; i <= n; i++)
        res.push_back(1 + res[i - 1] + res[i - 2]);

    cout << res[n];
}