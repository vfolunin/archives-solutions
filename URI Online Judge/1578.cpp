#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int size;
    cin >> size;

    vector<vector<string>> a(size, vector<string>(size));
    vector<int> width(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            unsigned long long x;
            cin >> x;
            a[i][j] = to_string(x * x);
            width[j] = max<int>(width[j], a[i][j].size());
        }
    }

    if (test > 1)
        cout << "\n";
    cout << "Quadrado da matriz #" << test + 3 << ":\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(width[j]) << a[i][j];
            cout << (j + 1 < size ? " " : "\n");
        }
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