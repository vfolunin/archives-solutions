#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

char getHash(string &s) {
    char res = 0;
    for (char c : s)
        res ^= c;
    return res;
}

bool solve() {
    int lineCount;
    cin >> lineCount;
    cin.ignore();

    if (!lineCount)
        return 0;

    int collisionCount = 0;
    map<string, int> lines;
    map<char, int> hashes;

    for (int i = 0; i < lineCount; i++) {
        string line;
        getline(cin, line);

        char hash = getHash(line);
        collisionCount += hashes[hash] - lines[line];
        lines[line]++;
        hashes[hash]++;
    }

    cout << lines.size() << " " << collisionCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}