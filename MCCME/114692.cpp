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

    long long a, b, c, n;
    cin >> a >> b >> c >> n;

    cout << max(a * b - c, 0LL) / n;
}