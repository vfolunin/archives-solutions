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

    int l = 0, r = count(s.begin(), s.end(), 'c');
    long long res = 0;

    for (char c : s) {
        r -= c == 'c';
        if (c == 'b')
            res += l * r;
        l += c == 'a';
    }

    cout << res;
}