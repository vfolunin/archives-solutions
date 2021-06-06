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

    while (true) {
        int n;
        cin >> n;

        if (n == 42)
            break;

        cout << n << "\n";
    }
}