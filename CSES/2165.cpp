#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int n, int a, int b, int c) {
    if (!n)
        return;
    rec(n - 1, a, c, b);
    cout << a << " " << c << "\n";
    rec(n - 1, b, a, c);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";
    rec(n, 1, 2, 3);
}