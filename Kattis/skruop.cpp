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

    int level = 7;
    for (int i = 0; i < opCount; i++) {
        string op;
        cin >> op >> op;

        if (op == "op!")
            level = min(level + 1, 10);
        else
            level = max(level - 1, 0);
    }

    cout << level;
}