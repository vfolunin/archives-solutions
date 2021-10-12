#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    int a = 9 * x * x + y * y;
    int b = 2 * x * x + 25 * y * y;
    int c = -100 * x + y * y * y;

    if (a > b && a > c)
        cout << "Rafael ganhou\n";
    else if (b > a && b > c)
        cout << "Beto ganhou\n";
    else
        cout << "Carlos ganhou\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}