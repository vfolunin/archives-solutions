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

    int n;
    cin >> n;

    vector<vector<long long>> c(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }
}