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

    long long a, b, c;
    cin >> a >> b >> c;

    c = max(c - a + 1, 0LL);
    a -= b;

    cout << (c + a - 1) / a + 1;
}