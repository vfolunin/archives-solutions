#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n, a, b;
    cin >> n >> a >> b;

    long long count = clamp(b - a, 0LL, n);
    cout << (b - count + 1 + b) * count / 2 + (n - count) * a;
}