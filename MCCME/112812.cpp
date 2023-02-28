#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
     
    int teamCount, wordCount;
    cin >> teamCount >> wordCount;

    unordered_map<string, int> lastTeam;
    for (int i = 0; i < wordCount; i++) {
        int team;
        string word;
        cin >> team >> word;
        lastTeam[word] = team - 1;
    }

    vector<int> res(teamCount);
    for (auto &[word, team] : lastTeam)
        res[team]++;

    for (int value : res)
        cout << value << " ";
}