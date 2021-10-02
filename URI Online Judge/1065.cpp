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

    int even = 0;
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        even += x % 2 == 0;
    }

    cout << even << " valores pares\n";
}