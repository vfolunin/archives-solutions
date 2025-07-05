#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (!a && !b && !c)
        return 0;

    if (a == b + c)
        cout << "Maryam Win!!!\n";
    else if (a == abs(b - c))
        cout << "Majid Win!!!\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}