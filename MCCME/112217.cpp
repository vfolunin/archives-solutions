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
    for (int i = n; i; i--) {
        if (i % 2 == 0) {
            found = 1;
            cout << (1LL << i) << " ";
        }
    }

    if (!found)
        cout << 0;
}