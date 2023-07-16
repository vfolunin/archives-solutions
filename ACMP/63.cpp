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

    int sum, product;
    cin >> sum >> product;

    for (int a = 1, b = sum - 1; a <= b; a++, b--) {
        if (a * b == product) {
            cout << a << " " << b;
            break;
        }
    }
}