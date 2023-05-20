#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int f(int m, int n) {
    if (!m)
        return n + 1;
    if (!n)
        return f(m - 1, 1);
    return f(m - 1, f(m, n - 1));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, n;
    cin >> m >> n;

    cout << f(m, n);
}