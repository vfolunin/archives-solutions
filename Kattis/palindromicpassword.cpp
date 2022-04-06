#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> preparePalindromes() {
    vector<int> palindromes;
    for (int i = 100; i < 1000; i++) {
        string left = to_string(i);
        string right = left;
        reverse(right.begin(), right.end());
        palindromes.push_back(stoi(left + right));
    }
    return palindromes;
}

void solve() {
    int n;
    cin >> n;

    static vector<int> palindromes = preparePalindromes();
    auto it = lower_bound(palindromes.begin(), palindromes.end(), n);

    if (it == palindromes.begin() || n - *prev(it) > *it - n)
        cout << *it << "\n";
    else
        cout << *prev(it) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}