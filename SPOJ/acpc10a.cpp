#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long a, b, c;
    cin >> a >> b >> c;

    if (!a && !b && !c)
        return 0;

    if (b - a == c - b)
        cout << "AP " << c + (c - b) << "\n";
    else
        cout << "GP " << c * (c / b) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}