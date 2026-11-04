#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Hasher {
    long long x, mod;
    vector<long long> p, h;

    Hasher(const string &s, long long x = 131, long long mod = 1e9 + 7) : x(x), mod(mod) {
        p.resize(s.size());
        h.resize(s.size());

        p[0] = 1;
        h[0] = s[0];

        for (int i = 1; i < s.size(); i++) {
            p[i] = p[i - 1] * x % mod;
            h[i] = (h[i - 1] * x % mod + s[i]) % mod;
        }
    }

    long long getHash(int l, int r) {
        long long res = h[r];
        if (l)
            res = (res - p[r - l + 1] * h[l - 1] % mod + mod) % mod;
        return res;
    }
};

struct PalindromeChecker {
    Hasher hasher, rHasher;

    PalindromeChecker(const string &s) : hasher(s), rHasher({ s.rbegin(), s.rend() }) {}

    bool isPalindrome(int l, int r) {
        return hasher.getHash(l, r) == rHasher.getHash(rHasher.p.size() - 1 - r, rHasher.p.size() - 1 - l);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    PalindromeChecker palindromeChecker(s);

    int size = s.size() - 1;
    while (size && !palindromeChecker.isPalindrome(s.size() - size, s.size() - 1))
        size--;

    cout << s << string(s.rbegin() + size, s.rend());
}