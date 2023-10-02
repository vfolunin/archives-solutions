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

    int pageCount, product;
    cin >> pageCount >> product;

    string s;
    for (int digit = 9; digit > 1; digit--) {
        while (product % digit == 0) {
            s += digit + '0';
            product /= digit;
        }
    }

    cout << (product == 1 && stoll(string(s.rbegin(), s.rend())) <= pageCount ? "YES" : "NO");
}