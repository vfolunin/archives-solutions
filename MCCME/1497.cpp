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

    if (a) {
        if (b % a)
            cout << "no solution";
        else
            cout << b / a;
    } else {
        if (b)
            cout << "no solution";
        else
            cout << "many solutions";
    }
}