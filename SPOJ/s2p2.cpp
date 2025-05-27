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

    int money, sell, buy, opCount;
    cin >> money >> sell >> buy >> opCount;

    for (int i = 0; i < opCount; i++) {
        char op;
        cin >> op;

        money += op == 'S' ? sell : -buy;
    }

    cout << max(money, 0);
}