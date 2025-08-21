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
    cin >> s >> s;

    s.erase(remove(s.begin(), s.end(), 'D'), s.end());

    int a = 0, b = 0, resA = 0, resB = 0;
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        a += s[i] == 'G';
        b += s[i] == 'A';

        if (i == s.size() - 1 || resA * (a + b) < a * (resA + resB)) {
            resA = a;
            resB = b;
        }
    }

    cout << resA << "-" << resB;
}