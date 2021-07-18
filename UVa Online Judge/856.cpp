#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string s;
    if (!(cin >> s))
        return 0;

    if (test)
        cout << "\n";

    static vector<string> digits = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    for (int d1 = 9; d1 >= 0; d1--) {
        for (int d2 = 9; d2 >= 0; d2--) {
            for (int d3 = 9; d3 >= 0; d3--) {
                string d = digits[d1] + digits[d2] + digits[d3];
                if (s.size() != d.size())
                    continue;

                string c;
                for (int i = 0; i < s.size(); i++) {
                    int si = s[i] - 'A', di = d[i] - 'a';
                    int delta = (si - di + 25) % 26;
                    c += 'A' + delta;
                }

                cout << c << " -> " << d << "\n";
            }
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}