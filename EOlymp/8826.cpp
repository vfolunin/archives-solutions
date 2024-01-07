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

    double x;
    cin >> x;

    cout << fixed << x - (x * x + 4) / 2 + x * x * x - 3 / (x + 7);
}