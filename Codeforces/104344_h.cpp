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

    int a, b;
    cin >> a >> b;

    if (a % 2 || b % 2) {
        cout << "S\n";
        if (a % 2)
            cout << "A ";
        if (b % 2)
            cout << "B";
    } else {
        cout << "N";
    }
}