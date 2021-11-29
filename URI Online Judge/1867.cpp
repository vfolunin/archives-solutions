#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitRoot(int n) {
    if (n < 10)
        return n;

    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return digitRoot(sum);
}

int digitRoot(const string &s) {
    int sum = 0;
    for (char c : s)
        sum += c - '0';
    return digitRoot(sum);
}

bool solve() {
    string a, b;
    cin >> a >> b;

    if (a == "0" && b == "0")
        return 0;

    int ra = digitRoot(a), rb = digitRoot(b);

    if (ra > rb)
        cout << "1\n";
    else if (ra == rb)
        cout << "0\n";
    else
        cout << "2\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}