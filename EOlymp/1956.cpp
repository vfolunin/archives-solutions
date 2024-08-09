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

    string s;
    cin >> s;

    string digits = "0123456789ABCDEF";
    int res = 0;

    for (char c : s)
        res = (res * 16 + digits.find(c)) % 5;

    cout << res;
}