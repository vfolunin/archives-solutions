#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> res(1e6 + 1);
    for (int i = 1; i < res.size(); i++)
        for (int j : { 1, 2, 3, 5, 7 })
            res[i] |= i > j && !res[i - j];
    return res;
}

void solve(int test) {
    int n;
    cin >> n;

    static vector<int> res = prepare();

    cout << "Case " << test << ": " << (res[n] ? "BOB\n" : "ALICE\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}