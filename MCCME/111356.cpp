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

    map<string, int> voteCount;
    int totalVoteCount = 0;
    for (string name; getline(cin, name); ) {
        voteCount[name]++;
        totalVoteCount++;
    }

    vector<string> names;
    for (auto &[name, voteCount] : voteCount)
        names.push_back(name);
    sort(names.begin(), names.end(), [&](string &a, string &b) {
        return voteCount[a] > voteCount[b];
    });

    cout << names[0] << "\n";
    if (voteCount[names[0]] * 2 <= totalVoteCount)
        cout << names[1];
}