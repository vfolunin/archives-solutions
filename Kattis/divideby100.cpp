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

    string num, den;
    cin >> num >> den;

    int denPower = den.size() - 1;

    string whole;
    if (num.size() <= denPower) {
        whole = "0";
        num = string(denPower - num.size(), '0') + num;
    } else {
        whole = num.substr(0, num.size() - denPower);
    }

    string frac = num.substr(num.size() - denPower);
    while (!frac.empty() && frac.back() == '0')
        frac.pop_back();

    cout << whole;
    if (!frac.empty() && frac != "0")
        cout << "." << frac;
}