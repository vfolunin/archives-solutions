#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    cout << "Teste " << test << "\n";

    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int da, db;
        cin >> da >> db;
        a += da;
        b += db;
        cout << a - b << "\n";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}