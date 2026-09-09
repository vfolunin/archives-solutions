#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(long long n) {
    if (n < 2)
        return 0;

    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    for (char digit : { '3', '4', '7' }) {
        if (s.find(digit) != -1) {
            cout << "no";
            return 0;
        }
    }

    if (!isPrime(stoll(s))) {
        cout << "no";
        return 0;
    }

    reverse(s.begin(), s.end());
    for (char &c : s)
        if (c == '6' || c == '9')
            c = '6' + '9' - c;
    
    cout << (isPrime(stoll(s)) ? "yes" : "no");
}