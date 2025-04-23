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

    int a, b;
    cin >> a >> b;

    if (a < 0)
        cout << (b < a ? "VASYA" : "PETYA");
    else if (!a)
        cout << (!b ? "VASYA" : "PETYA");
    else
        cout << (b > a ? "VASYA" : "PETYA");
}