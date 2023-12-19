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

    int n;
    cin >> n;

    double res = 0, part = 1;
    for (int i = 0; i < n; i++) {
        res += part / 2;
        part /= 4;
    }

    cout.precision(5);
    cout << fixed << 100 * res;
}