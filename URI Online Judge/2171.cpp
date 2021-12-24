#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    int k = 1;
    while ((k + 1) * (k + 2) / 2 <= n)
        k++;
    int a = k * (k + 1) / 2;
    int b = n - a;

    cout << a << " " << b << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}