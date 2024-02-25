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

    int a, b, n;
    cin >> a >> b >> n;

    int resT = n, resKa = 0, resKb = 0;
    for (int ka = 0; ka * a <= n; ka++) {
        int kb = (n - ka * a) / b;
        int t = n - ka * a - kb * b;

        if (resT > t || resT == t && resKa + resKb < ka + kb) {
            resT = t;
            resKa = ka;
            resKb = kb;
        }
    }

    cout << resKa + resKb;
    if (resT)
        cout << " " << resT;
}