#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;

    cout << "Case " << test << ":";

    for (int i = sqrt(n) - 1; i >= 1; i--) {
        int x = n - i * i;
        if (x % i == 0)
            cout << " " << x;
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int test = 1; test <= n; test++)
        solve(test);
}