#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <array>
using namespace std;

bool compare(pair<string, array<int, 3>> &a, pair<string, array<int, 3>> &b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<string, array<int, 3>> medalCount;
    
    string name, a, b, c;
    while (getline(cin, name) && getline(cin, a) && getline(cin, b) && getline(cin, c)) {
        medalCount[a][0]++;
        medalCount[b][1]++;
        medalCount[c][2]++;
    }

    vector<pair<string, array<int, 3>>> res(medalCount.begin(), medalCount.end());
    sort(res.begin(), res.end(), compare);

    cout << "Quadro de Medalhas\n";
    for (auto &[name, medals] : res)
        cout << name << " " << medals[0] << " " << medals[1] << " " << medals[2] << "\n";
}