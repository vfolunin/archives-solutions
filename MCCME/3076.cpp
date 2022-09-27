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

    while (a > b) {
        if (a % 2 == 0 && a / 2 >= b) {
            cout << ":2\n";
            a /= 2;
        } else {
            cout << "-1\n";
            a--;            
        }
    }
}