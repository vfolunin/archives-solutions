#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long add(long long n, long long p) {
    n *= (100 + p);
    return n / 100 + (n % 100 >= 50);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n, a, b;
    cin >> n >> a >> b;

    n = add(n, a);
    n = add(n, -b);

    cout << n;
}