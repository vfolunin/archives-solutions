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

    int a, b;
    cin >> a >> b;

    vector<vector<vector<char>>> grundy(a + b + 1, vector<vector<char>>(a + b + 1, vector<char>(b + 1)));
    for (int k3 = 0; k3 <= b; k3++) {
        for (int k2 = 0; k2 <= a + b - k3; k2++) {
            for (int k1 = 0; k1 <= a - k2 + b - k3; k1++) {
                set<char> transitions;

                if (k1) {
                    transitions.insert(grundy[k1 - 1][k2][k3]);
                }
                if (k2) {
                    transitions.insert(grundy[k1 + 1][k2 - 1][k3]);
                    transitions.insert(grundy[k1][k2 - 1][k3]);
                }
                if (k3) {
                    transitions.insert(grundy[k1][k2 + 1][k3 - 1]);
                    transitions.insert(grundy[k1 + 1][k2][k3 - 1]);
                    transitions.insert(grundy[k1][k2][k3 - 1]);
                }

                while (transitions.count(grundy[k1][k2][k3]))
                    grundy[k1][k2][k3]++;
            }
        }
    }

    cout << (grundy[0][a][b] ? 1 : 2);
}