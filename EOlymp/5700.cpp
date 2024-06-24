#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int a, b;
    string op;
    cin >> a >> op >> b;

    if (op == "E")
        return 0;

    int res;
    if (op == "<")
        res = a < b;
    else if (op == "<=")
        res = a <= b;
    else if (op == ">")
        res = a > b;
    else if (op == ">=")
        res = a >= b;
    else if (op == "==")
        res = a == b;
    else
        res = a != b;

    cout << "Case " << test << ": " << (res ? "true\n" : "false\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}