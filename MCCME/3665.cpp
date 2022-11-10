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
 
    int a = 0, b = 0, c = 0, prevI = -1, res = 1e9;

    for (int i = 1; 1; i++) {
        cin >> c;

        if (!c)
            break;

        if (a && b && a < b && b > c) {
            if (prevI != -1)
                res = min(res, i - prevI);
            prevI = i;
        }

        a = b;
        b = c;
    }

    cout << (res != 1e9 ? res : 0);
}