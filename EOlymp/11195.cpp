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

    string alphabet, letters;
    cin >> alphabet >> letters;

    int res = 1, pos = -1;
    for (char letter : letters) {
        int nextPos = alphabet.find(letter);
        res += nextPos <= pos;
        pos = nextPos;
    }

    cout << res;
}