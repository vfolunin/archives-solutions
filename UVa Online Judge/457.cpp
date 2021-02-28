#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    vector<int> dna(10);
    for (int &x : dna)
        cin >> x;

    vector<vector<int>> culture(2, vector<int>(42));
    culture[0][20] = 1;

    if (test)
        cout << "\n";
    for (int i = 0; i < 50; i++) {
        static string symbols = " .xW";
        for (int j = 1; j <= 40; j++)
            cout << symbols[culture[0][j]];
        cout << "\n";

        for (int j = 1; j <= 40; j++)
            culture[1][j] = dna[culture[0][j - 1] + culture[0][j] + culture[0][j + 1]];
        swap(culture[0], culture[1]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}