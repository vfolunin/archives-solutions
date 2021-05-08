#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int signCount;
    cin >> signCount;

    if (!signCount)
        return 0;

    vector<int> sign(signCount);
    for (int &n : sign) {
        string s;
        cin >> s;
        for (char c : s)
            n = n * 2 + (c == 'Y');
    }

    static vector<int> digit = {
        0b1111011,
        0b1111111,
        0b1110000,
        0b1011111,
        0b1011011,
        0b0110011,
        0b1111001,
        0b1101101,
        0b0110000,
        0b1111110
    };

    for (int l = 0, r = signCount - 1; r < 10; l++, r++) {
        bool ok = 1;
        int burn = 0b1111111;

        for (int i = 0; i < signCount; i++) {
            for (int bit = 0; bit < 7; bit++) {
                if ((sign[i] & (1 << bit)) && !(digit[l + i] & burn & (1 << bit))) {
                    ok = 0;
                    break;
                }
                if (!(sign[i] & (1 << bit)) && (digit[l + i] & burn & (1 << bit)))
                    burn ^= (1 << bit);
            }
        }

        if (ok) {
            cout << "MATCH\n";
            return 1;
        }
    }

    cout << "MISMATCH\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}