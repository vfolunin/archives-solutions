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

    long long l = 0, r = count(s.begin(), s.end(), 'A'), res = 0;
    for (char c : s) {
        if (c == 'A') {
            l++;
            r--;
        } else if (c == 'B') {
            res += l * r;
        }
    }

    cout << res;
}