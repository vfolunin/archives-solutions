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

    if (n == 1)
        return res = 1;

    for (int d = 2; d <= 9; d++)
        if (n % d == 0)
            res = (res + rec(n / d)) % 101;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    int res = rec(n);

    for (int d = 2; d <= 9; d++)
        while (n % d == 0)
            n /= d;

    cout << (n == 1 ? res : 0);
}