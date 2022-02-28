#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int dvdCount;
    cin >> dvdCount;

    int opCount = 0, curDvdIndex = 1;

    for (int i = 0; i < dvdCount; i++) {
        int dvd;
        cin >> dvd;

        if (dvd == curDvdIndex)
            curDvdIndex++;
        else
            opCount++;
    }

    cout << opCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}