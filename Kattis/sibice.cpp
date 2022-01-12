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

    int matchCount, h, w;
    cin >> matchCount >> h >> w;

    int maxLengthSquared = h * h + w * w;

    for (int i = 0; i < matchCount; i++) {
        int matchLength;
        cin >> matchLength;

        cout << (matchLength * matchLength <= maxLengthSquared ? "DA\n" : "NE\n");
    }
}