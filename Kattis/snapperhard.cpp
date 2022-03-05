#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int bit, n;
    cin >> bit >> n;

    int mask = (1 << bit) - 1;

    cout << "Case #" << test << ": ";
    cout << ((n & mask) == mask ? "ON\n" : "OFF\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}