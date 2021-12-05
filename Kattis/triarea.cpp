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

    int h, b;
    cin >> h >> b;

    cout.precision(8);
    cout << fixed << 0.5 * h * b;
}