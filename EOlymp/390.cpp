#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long factorial(int n) {
    static vector<long long> memo(15);
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

    map<char, int> count;
    for (char c : s)
        count[c]++;

    long long res = factorial(s.size());
    for (auto &[c, count] : count)
        res /= factorial(count);

    cout << res;
}