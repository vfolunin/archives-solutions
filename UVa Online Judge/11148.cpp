#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    string line;
    getline(cin, line);
    stringstream ss(line);

    long long num = 1, den = 1;

    while (ss.peek() != EOF) {
        if (!isdigit(ss.peek())) {
            ss.get();
            continue;
        }

        long long curInt = 0, curNum = 0, curDen = 1;;
        ss >> curNum;

        if (ss.peek() == '-') {
            curInt = curNum;
            ss.get();
            ss >> curNum;
        }

        if (ss.peek() == '/') {
            ss.get();
            ss >> curDen;
        }

        num *= curInt * curDen + curNum;
        den *= curDen;
    }

    long long d = gcd(num, den);
    num /= d;
    den /= d;

    if (num >= den) {
        cout << num / den;
        num %= den;
        if (num)
            cout << "-" << num << "/" << den;
    } else if (num) {
        cout << num << "/" << den;
    } else {
        cout << "0";
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}