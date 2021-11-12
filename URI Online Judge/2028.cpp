#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    if (!(cin >> n))
        return 0;

    cout << "Caso " << test << ": " << n * (n + 1) / 2 + 1 << " numero" << (n ? "s" : "") << "\n0";
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            cout << " " << i;
    cout << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}