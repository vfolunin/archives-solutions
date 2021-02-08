#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int codeSize;
    cin >> codeSize;

    if (!codeSize)
        return 0;

    vector<int> code(codeSize);
    for (int &x : code)
        cin >> x;

    cout << "Game " << test << ":\n";
    while (1) {
        vector<int> guess(codeSize);
        for (int &x : guess)
            cin >> x;

        if (!guess[0])
            break;

        int exact = 0;
        map<int, int> codeCount, guessCount;
        for (int i = 0; i < codeSize; i++) {
            if (code[i] == guess[i]) {
                exact++;
            } else {
                codeCount[code[i]]++;
                guessCount[guess[i]]++;
            }
        }

        int notExact = 0;
        for (auto &[key, count] : codeCount)
            notExact += min(count, guessCount[key]);
        
        cout << "    (" << exact << "," << notExact << ")\n";
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}