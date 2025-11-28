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

    int a, b, u, d;
    cin >> a >> b >> u >> d;

    if (a < b)
        cout << (b - a) * u;
    else
        cout << (a - b) * d;
}