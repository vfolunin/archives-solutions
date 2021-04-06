#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<vector<string>> tests(3, vector<string>(3));
    for (vector<string> &test : tests)
        for (string &token : test)
            cin >> token;

    for (char letter = 'A'; letter <= 'L'; letter++) {
        for (string type : { "light", "heavy" }) {
            bool ok = 1;
            for (int i = 0; ok && i < 3; i++) {
                if (tests[i][0].find(letter) != -1)
                    ok &= tests[i][2] == (type == "light" ? "down" : "up");
                else if (tests[i][1].find(letter) != -1)
                    ok &= tests[i][2] == (type == "light" ? "up" : "down");
                else
                    ok &= tests[i][2] == "even";
            }
            if (ok) {
                cout << letter << " is the counterfeit coin and it is " << type << ".\n";
                return;
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}