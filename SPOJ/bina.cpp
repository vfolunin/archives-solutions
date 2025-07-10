#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string as, bs;
    cin >> as >> bs;

    unsigned long long a = stoull(as, 0, 2);
    unsigned long long b = stoull(bs, 0, 2);

    cout << "Case " << test << ": " << (b && a % b == 0 ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}