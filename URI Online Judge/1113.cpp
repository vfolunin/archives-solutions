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

    while (1) {
        int a, b;
        cin >> a >> b;

        if (a == b)
            break;

        if (a < b)
            cout << "Crescente\n";
        else
            cout << "Decrescente\n";
    }
}