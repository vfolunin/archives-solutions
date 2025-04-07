#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int maxNum = -1e9;
    string maxStr;

    for (string s; cin >> s; ) {
        if (isdigit(s.back()))
            maxNum = max(maxNum, stoi(s));
        else
            maxStr = max(maxStr, s);
    }

    cout << maxNum << "\n" << maxStr;
}