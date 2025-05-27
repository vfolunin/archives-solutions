#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a, b;
    char op;
    cin >> a >> op >> b;

    if (op == '+')
        cout << a + b << "\n";
    else if (op == '-')
        cout << a - b << "\n";
    else if (op == '*')
        cout << a * b << "\n";
    else if (op == '&')
        cout << (a & b) << "\n";
    else if (op == '|')
        cout << (a | b) << "\n";
    else if (op == '^')
        cout << (a ^ b) << "\n";
    else if (!b)
        cout << "Error\n";
    else if (op == '/')
        cout << a / b << "\n";
    else
        cout << a % b << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}