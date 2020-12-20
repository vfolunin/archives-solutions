#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

long long reverse(long long n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoi(s);
}

bool isPalindrome(long long n) {
    string s = to_string(n), r = s;
    reverse(r.begin(), r.end());
    return r == s;
}

void solve() {
    long long n;
    cin >> n;

    int iterations = 0;
    while (!isPalindrome(n)) {
        n += reverse(n);
        iterations++;
    }

    cout << iterations << " " << n << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}