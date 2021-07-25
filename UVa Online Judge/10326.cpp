#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int rootCount;
    if (!(cin >> rootCount))
        return 0;

    vector<long long> coeff(rootCount + 1);
    coeff[0] = 1;

    for (int i = 0; i < rootCount; i++) {
        int root;
        cin >> root;

        for (int j = i + 1; j > 0; j--)
            coeff[j] = coeff[j - 1] - root * coeff[j];
        coeff[0] *= -root;
    }

    for (int i = coeff.size() - 1; i >= 0; i--) {
        if (i && !coeff[i])
            continue;
        if (i < coeff.size() - 1)
            cout << (coeff[i] >= 0 ? " + " : " - ");
        if (!i || abs(coeff[i]) != 1)
            cout << abs(coeff[i]);
        if (i > 0)
            cout << "x";
        if (i > 1)
            cout << "^" << i;
    }
    cout << " = 0\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}