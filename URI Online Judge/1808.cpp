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

    double num = 0, den = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            num += 10;
            i--;
        } else {
            num += s[i] - '0';
        }
        den++;
    }

    cout.precision(2);
    cout << fixed << num / den << "\n";
}