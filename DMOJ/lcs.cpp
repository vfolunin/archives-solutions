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

    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;

    vector<vector<int>> lcs(aSize + 1, vector<int>(bSize + 1));
    for (int ai = 1; ai <= aSize; ai++) {
        for (int bi = 1; bi <= bSize; bi++) {
            if (a[ai - 1] == b[bi - 1])
                lcs[ai][bi] = lcs[ai - 1][bi - 1] + 1;
            else
                lcs[ai][bi] = max(lcs[ai - 1][bi], lcs[ai][bi - 1]);
        }
    }

    cout << lcs[aSize][bSize];
}