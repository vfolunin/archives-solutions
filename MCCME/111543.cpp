#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int read() {
    string s;
    cin >> s;

    return (((s.back() - '0') * 8 - 6 + 10) % 10 * 5 + 7) % 10;
}

int factorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res *= n;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout << factorial(abs(read() - read()));
}