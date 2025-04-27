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

    int n;
    char c;
    cin >> n >> c;

    if (n < 3) {
        if (c == 'A' || c == 'D')
            cout << "window";
        else
            cout << "aisle";
    } else if (n < 21) {
        if (c == 'A' || c == 'F')
            cout << "window";
        else
            cout << "aisle";
    } else {
        if (c == 'A' || c == 'K')
            cout << "window";
        else if (c == 'C' || c == 'D' || c == 'G' || c == 'H')
            cout << "aisle";
        else
            cout << "neither";
    }
}