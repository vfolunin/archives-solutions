#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int aSize, bSize;
    cin >> aSize >> bSize;

    if (!aSize && !bSize)
        return 0;

    vector<int> a(aSize);
    for (int &x : a)
        cin >> x;

    vector<int> b(bSize);
    for (int &x : b)
        cin >> x;

    vector<vector<int>> lcs(aSize + 1, vector<int>(bSize + 1));
    for (int i = 1; i <= aSize; i++) {
        for (int j = 1; j <= bSize; j++) {
            if (a[i - 1] == b[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    
    cout << "Twin Towers #" << test << "\n";
    cout << "Number of Tiles : " << lcs[aSize][bSize] << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}