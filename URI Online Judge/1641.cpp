#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int r, h, w;
    if (!(cin >> r >> h >> w))
        return 0;

    if (hypot(h, w) <= 2 * r + 1e-9)
        cout << "Pizza " << test << " fits on the table.\n";
    else
        cout << "Pizza " << test << " does not fit on the table.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    for (int test = 1; solve(test); test++);
}