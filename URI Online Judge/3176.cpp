#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int gnomeCount;
    cin >> gnomeCount;

    vector<pair<string, int>> gnomes(gnomeCount);
    for (auto &[name, age] : gnomes)
        cin >> name >> age;

    sort(gnomes.begin(), gnomes.end(), compare);

    int teamCount = gnomeCount / 3;

    for (int i = 0; i < teamCount; i++) {
        cout << "Time " << i + 1 << "\n";
        for (int j = i; j < gnomeCount; j += teamCount)
            cout << gnomes[j].first << " " << gnomes[j].second << "\n";
        cout << "\n";
    }
}