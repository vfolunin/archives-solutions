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

    string text, word;
    cin >> text >> word;

    int positionCount = 0;
    for (int from = 0; from + word.size() <= text.size(); from++) {
        bool ok = 1;
        for (int i = 0; ok && i < word.size(); i++)
            ok &= text[from + i] != word[i];
        positionCount += ok;
    }

    cout << positionCount << "\n";
}