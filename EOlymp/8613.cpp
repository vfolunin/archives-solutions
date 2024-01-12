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

    long long x;
    cin >> x;

    if (x >= 13)
        cout << 3 * x * x * x + 4 * x * x + 5 * x + 6;
    else
        cout << 3 * x * x * x - 2 * x * x - 3 * x - 4;
}