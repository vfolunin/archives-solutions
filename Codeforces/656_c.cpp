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

    string s;
    cin >> s;

    int res = 0;
    for (char c : s) {
        if (isupper(c))
            res += c - 'A' + 1;
        else if (islower(c))
            res -= c - 'a' + 1;
    }

    cout << res;
}