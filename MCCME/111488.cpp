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

    int type, n, a, b, c;
    cin >> type >> n >> a >> b >> c;

    if (type == 1) {
        int ab = max(0, a + b - n);
        int abc = max(0, ab + c - n);
        cout << abc;
    } else {
        cout << min({ a, b, c });
    }
}