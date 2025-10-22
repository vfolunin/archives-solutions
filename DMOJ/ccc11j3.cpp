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

    int a, b;
    cin >> a >> b;

    int res = 2;
    while (a >= b) {
        int c = a - b;
        a = b;
        b = c;
        res++;
    }

    cout << res;
}