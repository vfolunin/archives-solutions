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

    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < 3; i++) {
        a += b;
        if (a >= c) {
            cout << a;
            return 0;
        }
    }

    cout << "Who knows...";
}