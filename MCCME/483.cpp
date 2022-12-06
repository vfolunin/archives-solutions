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

    int partyCount, blankCount;
    cin >> partyCount >> blankCount;

    vector<int> votes(partyCount);
    int totalVotes = 0;

    for (int i = 0; i < blankCount; i++) {
        string blank;
        cin >> blank;
        if (blank.find('+') != -1 && blank.find('+') == blank.rfind('+')) {
            votes[blank.find('+')]++;
            totalVotes++;
        }
    }

    for (int i = 0; i < partyCount; i++)
        if (votes[i] * 100 >= totalVotes * 7)
            cout << i + 1 << " ";
}