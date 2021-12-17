#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int argCount;
    cin >> argCount;

    if (!argCount)
        return 0;

    int res;
    cin >> res;

    for (int i = 1; i < argCount; i++) {
        char op;
        int arg;
        cin >> op >> arg;
        res += (op == '+' ? arg : -arg);
    }

    cout << "Teste " << test << "\n";
    cout << res << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    for (int test = 1; solve(test); test++);
}