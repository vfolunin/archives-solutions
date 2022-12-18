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

    long long a, b, n;
    cin >> a >> b >> n;

    n *= a * 100 + b;

    cout << n / 100 << " " << n % 100;
}