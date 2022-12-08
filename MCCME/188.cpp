#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    unordered_map<char, int> count;
    for (char c : s)
        count[c]++;

    long long res = factorial(s.size());
    for (auto &[c, count] : count)
        res /= factorial(count);

    cout << res;
}