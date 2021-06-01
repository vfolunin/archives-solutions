#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<pair<int, int>> masks;
    string line;
    while (cin >> line && line != ".") {
        int maskP = 0, maskN = 0;
        for (int i = 1; i < line.size(); i += 2) {
            if (line[i - 1] == '+')
                maskP |= 1 << (line[i] - 'A');
            else
                maskN |= 1 << (line[i] - 'A');
        }
        masks.push_back({ maskP, maskN });
    }

    if (masks.empty())
        return 0;

    for (int pizzaMaskP = 0, pizzaMaskN = (1 << 16) - 1; pizzaMaskP < (1 << 16); pizzaMaskP++, pizzaMaskN--) {
        bool ok = 1;
        for (auto &[maskP, maskN] : masks) {
            ok &= (pizzaMaskP & maskP) || (pizzaMaskN & maskN);
            if (!ok)
                break;
        }
        if (!ok)
            continue;

        cout << "Toppings: ";
        for (int bit = 0; bit < 16; bit++)
            if (pizzaMaskP & (1 << bit))
                cout << (char)('A' + bit);
        cout << "\n";
        return 1;
    }

    cout << "No pizza can satisfy these requests.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}