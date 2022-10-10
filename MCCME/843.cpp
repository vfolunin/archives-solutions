#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int n) {
    static vector<int> memo(1001, -1e9);
    int &res = memo[n];
    if (res != -1e9)
        return res;

    if (n <= 1)
        return res = 1;

    if (n % 2 == 0)
        return res = rec(n / 2) + rec(n / 2 - 1);
    else
        return res = rec(n / 2) - rec(n / 2 - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << rec(n);
}