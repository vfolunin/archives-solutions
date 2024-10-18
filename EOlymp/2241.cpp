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
    a *= 101;
    b *= 101;

    for (int res = 1; res * b + a <= 5e4; res++) {
        if ((res * b + a) % 100 == 0) {
            cout << "YES\n" << res;
            return 0;
        }
    }

    cout << "NO";
}