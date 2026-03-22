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

    int a, b, c;
    cin >> a >> b >> c;

    if (c < 0) {
        cout << "NO SOLUTION";
        return 0;
    }

    c = c * c - b;

    if (!a && !c) {
        cout << "MANY SOLUTIONS";
        return 0;
    }

    if (!a || c % a) {
        cout << "NO SOLUTION";
        return 0;
    }

    cout << c / a;
}