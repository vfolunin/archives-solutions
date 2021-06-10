#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;
    
    int sum = 0;
    for (char c : s)
        if (isdigit(c))
            sum += c - '0';

    cout << (s[0] != '-' && sum > 0 && sum % 3 == 0) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}