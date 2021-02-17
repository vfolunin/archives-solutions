#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;

    cout << "Case #" << test << ": " << n;

    int i = 2;
    while (n % i)
        i++;
    cout << " = " << i << " * " << n / i;
    
    i++;
    while (n % i)
        i++;
    cout << " = " << i << " * " << n / i << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}