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

    int a, b, c, ka, kb, kc;
    cin >> a >> b >> c >> ka >> kb >> kc;

    cout << ka + kb + kc << " " << ka * a + kb * b + kc * c << "\n";
}