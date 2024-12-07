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

    int playerCount, tagCount;
    cin >> playerCount >> tagCount;

    vector<string> players(playerCount);
    for (string &player : players)
        cin >> player;

    string hunter = players[0];
    set<string> probablyHunter, cheater;

    for (int i = 0; i < tagCount; i++) {
        string a, tag, b;
        cin >> a >> tag >> b;

        if (a == hunter) {
            probablyHunter.erase(b);
            hunter = b;
        } else if (probablyHunter.count(a)) {
            probablyHunter.erase(a);
            if (b != hunter)
                probablyHunter.insert(b);
        } else {
            cheater.insert(a);
            if (b != hunter)
                probablyHunter.insert(b);
        }
    }

    cout << cheater.size() << "\n";
    for (const string &player : cheater)
        cout << player << " ";
}