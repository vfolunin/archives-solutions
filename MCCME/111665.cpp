#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int read() {
    int a, b, c;
    cin >> a >> b >> c;

    return (a + b + c) / gcd(a, gcd(b, c));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a = read();
    int b = read();

    cout << lcm(a, b);
}