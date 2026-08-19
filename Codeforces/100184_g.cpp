#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPalindrome(const string &s) {
    for (int l = 0, r = s.size() - 1; l < r; l++, r--)
        if (s[l] != s[r])
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int bestValue = 0, bestA, bestB;
    for (int a = 1; a < n; a++) {
        for (int b = a; b < n; b++) {
            if (isPalindrome(to_string(a * b)) && bestValue < a * b) {
                bestValue = a * b;
                bestA = a;
                bestB = b;
            }
        }
    }

    cout << bestA << " " << bestB;
}