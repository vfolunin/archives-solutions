#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitCount(int value) {
    return to_string(value).size();
}

bool isPrime(int n) {
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

    int n;
    string s;
    cin >> n >> s;

    int startValue = stoi(s);
    for (int i = 1; i < n && digitCount(startValue + i) <= s.size(); i++) {
        if (isPrime(startValue + i)) {
            cout << i - 1;
            return 0;
        }
    }

    cout << -1;
}