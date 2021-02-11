#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<pair<int, int>, int> matrixMultiplication(vector<int> &h, vector<int> &w) {
    char c;
    if (!(cin >> c))
        return { {0, 0}, -2 };
    if (c == '(') {
        auto [m1, r1] = matrixMultiplication(h, w);
        auto [m2, r2] = matrixMultiplication(h, w);
        cin >> c;
        if (r1 == -1 || r2 == -1 || m1.second != m2.first)
            return { {0, 0}, -1 };
        return { {m1.first, m2.second}, r1 + m1.first * m2.first * m2.second + r2 };
    } else {
        return { {h[c - 'A'], w[c - 'A']}, 0 };
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int matrixCount;
    cin >> matrixCount;

    vector<int> h(26), w(26);
    char name;
    for (int i = 0; i < matrixCount; i++)
        cin >> name >> h[name - 'A'] >> w[name - 'A'];

    while (1) {
        auto [_, r] = matrixMultiplication(h, w);
        if (r == -2)
            break;
        if (r != -1)
            cout << r << "\n";
        else
            cout << "error\n";
    }
}