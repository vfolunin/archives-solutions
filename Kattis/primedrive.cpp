#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return 0;

    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;

    return 1;
}

bool solve() {
    string s;
    int value;
    cin >> s >> value;

    if (s == "END" && !value)
        return 0;

    while (!isPrime(value)) {
        value++;
        if (value == 1e4) {
            value = 0;
            for (int i = s.size() - 1; 1; i--) {
                if (s[i] != 'Z') {
                    s[i]++;
                    fill(s.begin() + i + 1, s.end(), 'A');
                    break;
                }
            }
        }
    }

    cout << s << " " << setw(4) << setfill('0') << value << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}