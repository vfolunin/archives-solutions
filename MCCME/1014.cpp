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

    vector<vector<vector<int>>> grundy(a + b + 1, vector<vector<int>>(a + b + 1, vector<int>(b + 1)));
    for (int k3 = 0; k3 <= b; k3++) {
        for (int k2 = 0; k2 <= a + b - k3; k2++) {
            for (int k1 = 0; k1 <= a - k2 + b - k3; k1++) {
                set<int> transitions;

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

    if (grundy[0][a][b]) {
        vector<pair<int, int>> transitions;
        if (a && !grundy[1][a - 1][b])
            transitions.push_back({ 2, 1 });
        if (a && !grundy[0][a - 1][b])
            transitions.push_back({ 2, 2 });
        if (b && !grundy[0][a + 1][b - 1])
            transitions.push_back({ 3, 1 });
        if (b && !grundy[1][a][b - 1])
            transitions.push_back({ 3, 2 });
        if (b && !grundy[0][a][b - 1])
            transitions.push_back({ 3, 3 });

        cout << "1\n" << transitions.size() << "\n";
        for (auto &[type, count] : transitions)
            cout << type << " " << count << "\n";
    } else {
        cout << 2;
    }
}