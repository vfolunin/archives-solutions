#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPalindrome(int n) {
    string s = to_string(n);
    for (int l = 0, r = s.size() - 1; l < r; l++, r--)
        if (s[l] != s[r])
            return 0;
    return 1;
}

vector<int> getPalindromeDivisors(int n) {
    vector<int> divisors;

    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            if (isPalindrome(d))
                divisors.push_back(d);
            if (d * d != n && isPalindrome(n / d))
                divisors.push_back(n / d);
        }
    }

    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> divisors = getPalindromeDivisors(n);
    for (int i = 0; i < divisors.size(); i++)
        cout << divisors[i] << (i + 1 < divisors.size() ? "," : "");
}