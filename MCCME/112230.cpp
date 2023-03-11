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
    cin >> n;

    bool found = 0;
    for (int value : { 6, 28, 496, 8128, 33550336 }) {
        if (value <= n) {
            cout << value << " ";
            found = 1;
        }
    }

    if (!found)
        cout << 0;
}