#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;

    static vector<int> res = { 0, 1, 1, 1, 4, 6, 19, 43, 120, 307, 866, 2336, 6588, 18373, 52119, 147700, 422016 };

    cout << "Case #" << test << ": " << res[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}