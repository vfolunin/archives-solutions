#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int swapCount, lineCount;
    if (!(cin >> swapCount >> lineCount))
        return 0;

    string line;
    getline(cin, line);

    string swapA, swapB;
    getline(cin, swapA);
    getline(cin, swapB);

    map<char, char> swaps;
    for (int i = 0; i < swapCount; i++) {
        swaps[swapA[i]] = swapB[i];
        swaps[swapB[i]] = swapA[i];
    }

    for (int i = 0; i < lineCount; i++) {
        getline(cin, line);

        for (char &c : line)
            if (swaps.count(toupper(c)))
                c = isupper(c) ? swaps[c] : tolower(swaps[toupper(c)]);

        cout << line << "\n";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}