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

    double a, b, c;
    int n;
    cin >> a >> b >> c >> n;

    for (int i = 0; i < n; i++) {
        double da, db, dc, count;
        cin >> da >> db >> dc >> count;

        a -= da * count;
        b -= db * count;
        c -= dc * count;
    }

    cout << (a <= 1e-9 && b <= 1e-9 && c <= 1e-9 ? "YES" : "NO");
}