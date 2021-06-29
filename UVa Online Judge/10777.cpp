#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int doorCount;
    cin >> doorCount;

    double escapeProb = 0, resLen = 0;

    for (int i = 0; i < doorCount; i++) {
        double len, prob;
        cin >> len >> prob;

        if (len > 0) {
            resLen += len * prob;
            escapeProb += prob;
        } else {
            resLen += -len * prob;
        }
    }

    cout << "Case " << test << ": ";
    if (escapeProb < 1e-9) {
        cout << "God! Save me\n";
    } else {
        cout.precision(2);
        cout << fixed << resLen / escapeProb << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}