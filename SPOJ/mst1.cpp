#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> res(2e7 + 1);
    for (int i = 2; i < res.size(); i++) {
        res[i] = res[i - 1] + 1;
        for (int d : { 2, 3 })
            if (i % d == 0)
                res[i] = min(res[i], res[i / d] + 1);
    }
    return res;
}

void solve(int test) {
    int n;
    cin >> n;

    static vector<int> res = prepare();

    cout << "Case " << test << ": " << res[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}