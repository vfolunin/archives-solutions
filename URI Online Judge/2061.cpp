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

    int n, opCount;
    cin >> n >> opCount;

    for (int i = 0; i < opCount; i++) {
        string op;
        cin >> op;
        n += op == "fechou" ? 1 : -1;
    }

    cout << n << "\n";
}