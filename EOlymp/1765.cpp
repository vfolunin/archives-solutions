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

    int aSize;
    cin >> aSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    int bSize;
    cin >> bSize;

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;

    int cSize;
    cin >> cSize;

    vector<int> c(cSize);
    for (int &value : c)
        cin >> value;

    vector<vector<vector<int>>> lcs(aSize + 1, vector<vector<int>>(bSize + 1, vector<int>(cSize + 1)));
    for (int ai = 1; ai <= aSize; ai++) {
        for (int bi = 1; bi <= bSize; bi++) {
            for (int ci = 1; ci <= cSize; ci++) {
                if (a[ai - 1] == b[bi - 1] && a[ai - 1] == c[ci - 1])
                    lcs[ai][bi][ci] = lcs[ai - 1][bi - 1][ci - 1] + 1;
                else
                    lcs[ai][bi][ci] = max({ lcs[ai - 1][bi][ci], lcs[ai][bi - 1][ci], lcs[ai][bi][ci - 1] });
            }
        }
    }

    cout << lcs[aSize][bSize][cSize];
}