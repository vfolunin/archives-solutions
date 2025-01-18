#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long f(long long n) {
    return (n - 2) * (n - 1) / 2 + 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int r, l;
    cin >> r >> l;

    cout << f(r) - f(l);
}