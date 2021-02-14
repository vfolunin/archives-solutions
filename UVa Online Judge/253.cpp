#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rotate(string &s, int a, int b, int c, int d) {
    swap(s[a], s[b]);
    swap(s[b], s[c]);
    swap(s[c], s[d]);
}

bool solve() {
    string line;
    if (!(cin >> line))
        return 0;

    string a = line.substr(0, 6);
    string b = line.substr(6);

    for (int i = 0; i < 4; i++) {
        rotate(a, 0, 1, 5, 4);

        for (int j = 0; j < 4; j++) {
            rotate(a, 0, 2, 5, 3);

            for (int k = 0; k < 4; k++) {
                rotate(a, 1, 2, 4, 3);

                if (a == b) {
                    cout << "TRUE\n";
                    return 1;
                }
            }
        }
    }

    cout << "FALSE\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}