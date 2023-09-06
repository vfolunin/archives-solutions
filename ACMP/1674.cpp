#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b, c;
    cin >> a >> b >> c;

    long long res = lcm(a, b);
    res += (res / b - 1) * c;

    cout << res;
}