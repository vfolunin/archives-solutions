#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int uniqueDigitCount(int n) {
    string s = to_string(n);
    return set<char>(s.begin(), s.end()).size();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    while (uniqueDigitCount(n) > 1)
        n++;

    cout << n;
}