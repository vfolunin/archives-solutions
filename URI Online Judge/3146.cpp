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

    double r;
    cin >> r;

    cout.precision(2);
    cout << fixed << 6.28 * r << "\n";
}