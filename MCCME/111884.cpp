#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int personCount, totalVoteCount;
    cin >> personCount >> totalVoteCount;

    vector<string> persons(personCount);
    for (string &person : persons)
        cin >> person;

    vector<int> voteCount(personCount);
    int invalidVoteCount = 0;

    for (int i = 0; i < totalVoteCount; i++) {
        string vote;
        cin >> vote;

        if (count(vote.begin(), vote.end(), 'X') == 1)
            voteCount[vote.find('X')]++;
        else
            invalidVoteCount++;
    }

    vector<int> order(personCount);
    iota(order.begin(), order.end(), 0);
    stable_sort(order.begin(), order.end(), [&](int a, int b) {
        return voteCount[a] > voteCount[b];
    });

    cout.precision(2);
    for (int i : order)
        cout << persons[i] << " " << fixed << voteCount[i] * 100.0 / totalVoteCount + 1e-9 << "%\n";
    cout << "Invalid " << fixed << invalidVoteCount * 100.0 / totalVoteCount + 1e-9 << "%\n";
}