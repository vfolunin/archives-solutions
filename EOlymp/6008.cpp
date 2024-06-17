#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    cin >> n;

    if (n == -1)
        return 0;

    n *= 2;
    int root = sqrt(n);

    cout << "Case " << test << ": ";
    if (root * (root + 1) == n)
        cout << root << "\n";
    else
        cout << "bad\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}