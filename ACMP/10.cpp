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

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    for (int x = -100; x <= 100; x++)
        if (a * x * x * x + b * x * x + c * x + d == 0)
            cout << x << " ";
}