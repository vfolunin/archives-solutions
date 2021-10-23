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

    int a3, a1, ad, b3, b1, bd;
    cin >> a3 >> a1 >> ad >> b3 >> b1 >> bd;

    if (a3 * 3 + a1 != b3 * 3 + b1)
        cout << (a3 * 3 + a1 > b3 * 3 + b1 ? "C\n" : "F\n");
    else if (ad != bd)
        cout << (ad > bd ? "C\n" : "F\n");
    else
        cout << "=\n";
}