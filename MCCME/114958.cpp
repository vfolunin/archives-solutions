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

    long long a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;

    cout << (a * b + c * d) * e * f * g;
}