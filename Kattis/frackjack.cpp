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

    if (a > 21 && b > 21 || a == b)
        cout << "Jack";
    else if (b > 21 || a <= 21 && a > b)
        cout << "Alice";
    else
        cout << "Bertil";
}