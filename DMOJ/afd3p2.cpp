#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getInversionCount(vector<int> &guess, vector<int> &res) {
    int inversionCount = 0;
    for (int i = 0; i < guess.size(); i++)
        for (int j = i + 1; j < guess.size(); j++)
            inversionCount += find(res.begin(), res.end(), guess[i]) > find(res.begin(), res.end(), guess[j]);
    return inversionCount;
}

void printNextGuesses(vector<pair<vector<int>, int>> guesses) {
    vector<int> p = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    do {
        bool ok = 1;
        for (auto &[guess, inversionCount] : guesses)
            ok &= getInversionCount(guess, p) == inversionCount;

        if (ok) {
            for (int value : p)
                cout << value << " ";
            cout << "\n";
        }
    } while (next_permutation(p.begin(), p.end()));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i : { 2, 5, 3, 1, 4, 6, 8, 9, 7 })
        cout << i << "e5\n";

    if (0)
        printNextGuesses({
            { { 2, 1, 3, 4, 5, 6, 7, 8, 9 }, 6},
            { { 2, 6, 1, 4, 3, 5, 8, 7, 9 }, 10 },
            { { 2, 5, 1, 3, 4, 6, 9, 8, 7 }, 2 },
            { { 2, 1, 5, 3, 4, 9, 6, 8, 7 }, 4 },
            { { 2, 5, 1, 3, 4, 8, 6, 9, 7 }, 2 },
            { { 5, 2, 1, 3, 4, 6, 8, 9, 7 }, 2 }
        });
}