#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int n) {
    static map<int, int> memo;
    if (memo.count(n))
        return memo[n];
    int &res = memo[n];

    if (n <= 3)
        return res = (n == 3);

    return res = rec(n / 2) + rec((n + 1) / 2);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << rec(n);
}