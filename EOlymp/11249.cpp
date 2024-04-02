#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int f(int a, int b, int c, int n) {
    return n ? f(a, b, c, n - 1) + b * n + c : a;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b, c, n;
    cin >> a >> b >> c >> n;

    cout << f(a, b, c, n);
}