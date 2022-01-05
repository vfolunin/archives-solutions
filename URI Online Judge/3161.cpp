#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void lowerize(string &s) {
    for (char &c : s)
        c = tolower(c);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int fruitCount, lineCount;
    cin >> fruitCount >> lineCount;

    vector<string> fruits(fruitCount);
    for (string &fruit : fruits) {
        cin >> fruit;
        lowerize(fruit);
    }

    vector<string> lines(lineCount);
    for (string &line : lines) {
        cin >> line;
        lowerize(line);
    }

    for (string &fruit : fruits) {
        bool found = 0;
        for (int i = 0; !found && i < lineCount; i++)
            found |= lines[i].find(fruit) != -1;

        if (!found) {
            reverse(fruit.begin(), fruit.end());
            for (int i = 0; !found && i < lineCount; i++)
                found |= lines[i].find(fruit) != -1;
            reverse(fruit.begin(), fruit.end());
        }

        cout << "Sheldon " << (found ? "come" : "detesta") << " a fruta " << fruit << "\n";
    }
}