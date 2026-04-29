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

    int price, mod;
    cin >> price >> mod;

    for (int i = 1; i < 1000; i++) {
        if (price * i % 10 == 0 || price * i % 10 == mod) {
            cout << i;
            break;
        }
    }
}