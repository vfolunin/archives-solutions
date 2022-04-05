#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> preparePalindromes() {
    set<int> palindromeSet = { 0, 1 };
    for (int mask = 1; mask < 20000; mask++) {
        string left;
        for (int n = mask; n; n /= 2)
            left += '0' + n % 2;

        string right = left;
        reverse(left.begin(), left.end());

        palindromeSet.insert(stoi(left + right, 0, 2));
        palindromeSet.insert(stoi(left + "0" + right, 0, 2));
        palindromeSet.insert(stoi(left + "1" + right, 0, 2));
    }
    return { palindromeSet.begin(), palindromeSet.end() };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> palindromes = preparePalindromes();

    cout << palindromes[n];
}