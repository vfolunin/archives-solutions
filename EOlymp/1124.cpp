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

    for (int i = 0; i < n; i++) {
        cout << "a" << string(n - 1 - i, ' ');
        for (int j = 0; j <= i; j++)
            cout << (char)('a' + j);
        cout << "\n";
    }
}