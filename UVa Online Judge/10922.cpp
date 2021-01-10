#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int degree(int n) {
    if (n < 10)
        return 1;
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return 1 + degree(sum);
}

bool solve() {
    string s;
    cin >> s;

    if (s == "0")
        return 0;

    int sum = 0;
    for (char c : s)
        sum += c - '0';

    if (sum % 9)
        cout << s << " is not a multiple of 9.\n";
    else
        cout << s << " is a multiple of 9 and has 9-degree " << degree(sum) << ".\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}