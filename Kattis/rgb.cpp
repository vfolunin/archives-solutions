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

    long long r, g, b, limit;
    cin >> r >> g >> b >> limit;

    if (g || b)
        cout << r + limit;
    else if (limit > 1)
        cout << r - 1 + limit - 1;
    else
        cout << r;
}