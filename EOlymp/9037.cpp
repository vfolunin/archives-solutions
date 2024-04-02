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

    vector<int> res(n + 1, 1e9);
    res[0] = 0;

    for (int i = 1; i < res.size(); i++)
        for (char c : to_string(i))
            res[i] = min(res[i], 1 + res[i - (c - '0')]);

    cout << res[n];
}