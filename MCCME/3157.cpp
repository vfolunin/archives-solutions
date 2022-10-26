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
 
    int a, b = 0, c = 0, res = 0;

    for (int i = 0; 1; i++) {
        a = b;
        b = c;
        if (!(cin >> c))
            break;

        res += i >= 2 && a < b &&b > c;
    }

    cout << res;
}