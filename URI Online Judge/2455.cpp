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

    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    int p1 = a1 * b1, p2 = a2 * b2;
    if (p1 < p2)
        cout << "1\n";
    else if (p1 == p2)
        cout << "0\n";
    else
        cout << "-1\n";
}