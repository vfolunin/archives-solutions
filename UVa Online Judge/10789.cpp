#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

void solve(int test) {
    string s;
    cin >> s;

    map<char, int> count;
    for (char c : s)
        count[c]++;

    cout << "Case " << test << ": ";
    bool found = 0;
    for (auto &[c, k] : count) {
        if (isPrime(k)) {
            cout << c;
            found = 1;
        }
    }
    if (!found)
        cout << "empty";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}