#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool hasUniqueDigits(int n) {
    string s = to_string(n);
    return set<char>(s.begin(), s.end()).size() == s.size();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    for (int i = l; i <= r; i++)
        if (hasUniqueDigits(i))
            cout << i << " ";
}