#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool divisible(string &n, int d) {
    int mod = 0;
    for (char c : n)
        mod = (mod * 10 + c - '0') % d;
    return !mod;
}

bool solve(int test) {
    string year;
    if (!(cin >> year))
        return 0;

    bool isLeap = divisible(year, 400) || divisible(year, 4) && !divisible(year, 100);
    bool isH = divisible(year, 15);
    bool isB = isLeap && divisible(year, 55);

    if (test)
        cout << "\n";
    if (isLeap)
        cout << "This is leap year.\n";
    if (isH)
        cout << "This is huluculu festival year.\n";
    if (isB)
        cout << "This is bulukulu festival year.\n";
    if (!isLeap && !isH && !isB)
        cout << "This is an ordinary year.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}