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

void solve() {
    int power;
    cin >> power;

    vector<pair<string, int>> participants(1 << power);
    for (auto &[name, score] : participants)
        cin >> name >> score;

    sort(participants.begin(), participants.end(), compare);
    for (int from = 1, power = 0; from + (1 << power) <= participants.size(); from += 1 << power, power++)
        sort(participants.begin() + from, participants.begin() + from + (1 << power));

    for (auto &[name, _] : participants)
        cout << name << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}