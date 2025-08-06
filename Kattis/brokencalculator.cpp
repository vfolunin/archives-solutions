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

    int opCount;
    cin >> opCount;

    long long res = 1;
    for (int i = 0; i < opCount; i++) {
        long long a, b;
        char op;
        cin >> a >> op >> b;

        if (op == '+')
            res = a + b - res;
        else if (op == '-')
            res = (a - b) * res;
        else if (op == '*')
            res = a * b * a * b;
        else
            res = (a + 1) / 2;

        cout << res << "\n";
    }
}