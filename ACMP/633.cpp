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

    string team;
    getline(cin, team);

    vector<string> participants(3);
    for (string &participant : participants)
        cin >> participant;

    sort(participants.begin(), participants.end());

    cout << team;
    for (int i = 0; i < participants.size(); i++)
        cout << (i ? ", " : ": ") << participants[i];
}