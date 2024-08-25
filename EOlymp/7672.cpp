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

    int sum = 0;
    for (char c : s)
        sum += c - '0';

    string res;
    for (char &c : s) {
        for (char r = '0'; r <= '9'; r++) {
            if (c != r && (sum - c + r) % 3 == 0) {
                char prevC = c;
                c = r;
                res = max(res, s);
                c = prevC;
            }
        }
    }
    cout << res;
}