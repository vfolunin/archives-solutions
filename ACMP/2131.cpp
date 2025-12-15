#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<bool> getIsPrime(int n) {
    vector<bool> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i < isPrime.size(); i++)
        if (isPrime[i])
            for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                isPrime[j] = 0;

    return isPrime;
}

bool matches(const string &text, const string &pattern) {
    vector<vector<int>> res(text.size() + 1, vector<int>(pattern.size() + 1));

    res[0][0] = 1;
    for (int patternLen = 1; patternLen <= pattern.size(); patternLen++)
        res[0][patternLen] = res[0][patternLen - 1] && pattern[patternLen - 1] == '*';

    for (int textLen = 1; textLen <= text.size(); textLen++) {
        for (int patternLen = 1; patternLen <= pattern.size(); patternLen++) {
            if (isdigit(pattern[patternLen - 1])) {
                res[textLen][patternLen] = res[textLen - 1][patternLen - 1] && text[textLen - 1] == pattern[patternLen - 1];
            } else if (pattern[patternLen - 1] == '?') {
                res[textLen][patternLen] = res[textLen - 1][patternLen - 1];
            } else {
                for (int prevTextLen = 0; prevTextLen <= textLen; prevTextLen++)
                    res[textLen][patternLen] |= res[prevTextLen][patternLen - 1];
            }
        }
    }

    return res[text.size()][pattern.size()];
}

int digitProduct(int n) {
    int product = 1;
    while (n) {
        product *= n % 10;
        n /= 10;
    }
    return product;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string pattern;
    cin >> pattern;

    vector<bool> isPrime = getIsPrime(1e7);
    for (int i = 0; i < isPrime.size(); i++)
        if (isPrime[i] && matches(to_string(i), pattern))
            cout << i << " " << digitProduct(i) << "\n";
}