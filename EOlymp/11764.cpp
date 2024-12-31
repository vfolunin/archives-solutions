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

    string a, b;
    cin >> a >> b;

    vector<vector<int>> scsLen(a.size() + 1, vector<int>(b.size() + 1));

    for (int ai = 1; ai <= a.size(); ai++)
        scsLen[ai][0] = ai;

    for (int bi = 1; bi <= b.size(); bi++)
        scsLen[0][bi] = bi;

    for (int ai = 1; ai <= a.size(); ai++) {
        for (int bi = 1; bi <= b.size(); bi++) {
            if (a[ai - 1] == b[bi - 1])
                scsLen[ai][bi] = scsLen[ai - 1][bi - 1] + 1;
            else if (scsLen[ai - 1][bi] + 1 < scsLen[ai][bi - 1] + 1)
                scsLen[ai][bi] = scsLen[ai - 1][bi] + 1;
            else
                scsLen[ai][bi] = scsLen[ai][bi - 1] + 1;
        }
    }

    cout << scsLen.back().back();
}