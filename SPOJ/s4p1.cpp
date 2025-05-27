#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long factorial(int n) {
    static vector<long long> memo(10);
    long long &res = memo[n];
    if (res)
        return res;

    if (n <= 1)
        return res = 1;

    return res = factorial(n - 1) * n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    long long res = 0;
    for (int i = 0; i < s.size(); i++)
        res += factorial(s[i] - '0');

    cout << res;
}