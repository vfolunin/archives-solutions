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

    int res = (a + b + c) / 3;

    cout << res << "\n";
    cout << (res < 6 ? "DESAPROBADO" : "APROBADO");
}