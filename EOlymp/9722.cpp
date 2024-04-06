#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int num, den;
    if (!(cin >> num >> den))
        return 0;

    if (den)
        cout << num / den << "\n";
    else
        cout << "Division by zero\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}