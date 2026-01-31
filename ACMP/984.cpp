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

    int teamCount, winnerLimit, universityLimit;
    cin >> teamCount >> winnerLimit >> universityLimit;
    cin.ignore();

    vector<string> teamUniversity(teamCount);
    for (string &university : teamUniversity)
        getline(cin, university);

    vector<int> teamNumber(teamCount);
    for (int &number : teamNumber)
        cin >> number;

    unordered_map<string, int> universityWinnerCount;
    vector<string> res;
    for (int i = 0; i < teamCount && res.size() < winnerLimit; i++)
        if (universityWinnerCount[teamUniversity[i]]++ < universityLimit)
            res.push_back(teamUniversity[i] + " #" + to_string(teamNumber[i]));
    
    for (string &team : res)
        cout << team << "\n";
}