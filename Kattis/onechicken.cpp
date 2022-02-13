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

    if (a < b) {
        cout << "Dr. Chaz will have " << b - a << " piece";
        if (a + 1 < b)
            cout << "s";
        cout << " of chicken left over!";
    } else {
        cout << "Dr. Chaz needs " << a - b << " more piece";
        if (b + 1 < a)
            cout << "s";
        cout << " of chicken!";
    }
}