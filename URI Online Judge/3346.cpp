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

    double a, b;
    cin >> a >> b;

    double res = (1 + a / 100) * (1 + b / 100) - 1;

    cout << fixed << res * 100 << "\n";
}