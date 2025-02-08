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

    long long a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;

    for (int i = 0; i < k && i < 1e6; i++)
        a = max(0LL, min(a * b - c, d));

    cout << a;
}