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

    long long res = 1;
    for (char c : s) {
        if (c == 'X')
            res *= 10;
        else if (c == 'Y')
            res *= 6;
        else if (c == 'Z')
            res *= 4;
    }

    cout << res;
}