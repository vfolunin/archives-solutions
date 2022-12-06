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

    int p, x, y, n;
    cin >> p >> x >> y >> n;

    long long a = x * 100 + y;
    for (int i = 0; i < n; i++)
        a += a * p / 100;

    cout << a / 100 << " " << a % 100;
}