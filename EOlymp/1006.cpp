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

    int base;
    string a, b;
    cin >> base >> a >> a >> b >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int res = 0;

    for (int i = 0, carry = 0; i < a.size() || i < b.size() || carry; i++) {
        int aDigit = i < a.size() ? digits.find(a[i]) : 0;
        int bDigit = i < b.size() ? digits.find(b[i]) : 0;
        int sum = aDigit + bDigit + carry;
        res += sum >= base;
        carry = sum / base;
    }

    cout << res;
}