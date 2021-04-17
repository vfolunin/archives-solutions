#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int size;
    cin >> size;

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    int opCount;
    cin >> opCount;

    for (int i = 0; i < opCount; i++) {
        string op;
        cin >> op;

        if (op == "row") {
            int i1, i2;
            cin >> i1 >> i2;
            for (int j = 0; j < size; j++)
                swap(a[i1 - 1][j], a[i2 - 1][j]);
        } else if (op == "col") {
            int j1, j2;
            cin >> j1 >> j2;
            for (int i = 0; i < size; i++)
                swap(a[i][j1 - 1], a[i][j2 - 1]);
        } else if (op == "inc") {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    a[i][j] = (a[i][j] - '0' + 1) % 10 + '0';
        } else if (op == "dec") {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    a[i][j] = (a[i][j] - '0' + 9) % 10 + '0';
        } else {
            for (int i = 0; i < size; i++)
                for (int j = i + 1; j < size; j++)
                    swap(a[i][j], a[j][i]);
        }
    }

    cout << "Case #" << test << "\n";
    for (string &row : a)
        cout << row << "\n";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}