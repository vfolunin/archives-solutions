#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> a(2);
    for (int i = 0; a[0].size() < n || a[1].size() < n; i++)
        a[ones(i) % 2].push_back(i);

    cout << a[0][n - 1] + a[1][n - 1];
}