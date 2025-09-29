#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    char op;
    int a, b;
    cin >> op >> a >> b;

    if (op == '+')
        cout << a + b;
    else if (op == '-')
        cout << a - b;
    else if (op == '*')
        cout << a * b;
    else
        cout << a / b;
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}