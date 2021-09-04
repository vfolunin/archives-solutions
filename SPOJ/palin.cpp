#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string makePalindrome(string half, int odd) {
    string p = half;
    if (odd)
        half.pop_back();
    reverse(half.begin(), half.end());
    return p + half;
}

void solve() {
    string s;
    cin >> s;

    int odd = s.size() % 2;
    string half = s.substr(0, (s.size() + 1) / 2);

    if (string palindrome = makePalindrome(half, odd); s < palindrome) {
        cout << palindrome << "\n";
        return;
    }

    int p = half.size() - 1;
    while (p >= 0 && half[p] == '9')
        p--;

    if (p >= 0) {
        half[p]++;
        fill(half.begin() + p + 1, half.end(), '0');        
        cout << makePalindrome(half, odd) << "\n";
    } else {
        cout << "1" << string(s.size() - 1, '0') << "1\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}