#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b;
    char op;
    cin >> a >> op >> b;

    if (op == '+')
        cout << a + b;
    else if (op == '-')
        cout << a - b;
    else
        cout << a * b;
}