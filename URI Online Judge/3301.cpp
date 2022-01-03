#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isBetween(int a, int b, int c) {
    return a < b && b < c || a > b && b > c;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b, c;
    cin >> a >> b >> c;

    if (isBetween(b, a, c))
        cout << "huguinho\n";
    else if (isBetween(a, b, c))
        cout << "zezinho\n";
    else
        cout << "luisinho\n";
}