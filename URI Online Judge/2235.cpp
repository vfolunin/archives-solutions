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

    int a, b, c;
    cin >> a >> b >> c;

    if (a == b || a == c || b == c ||
        -a - b + c == 0 || -a + b - c == 0 || -a + b + c == 0 ||
        a - b - c == 0 || a - b + c == 0 || a + b - c == 0)
        cout << "S\n";
    else
        cout << "N\n";
}