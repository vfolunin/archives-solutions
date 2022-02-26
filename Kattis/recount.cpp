#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b) {
    return a.second > b.second;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<string, int> votes;

    while (1) {
        string name;
        getline(cin, name);

        if (name == "***")
            break;

        votes[name]++;
    }

    vector<pair<string, int>> pairs(votes.begin(), votes.end());
    sort(pairs.begin(), pairs.end(), compare);

    if (pairs.size() == 1 || pairs[0].second > pairs[1].second)
        cout << pairs[0].first;
    else
        cout << "Runoff!";
}