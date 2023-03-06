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

    vector<pair<string, string>> pairs;
    string name, surname;
    while (cin >> name >> surname)
        pairs.push_back({ name, surname });

    sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    for (int i = 0; i < pairs.size(); i++)
        cout << i + 1 << ". " << pairs[i].first << " " << pairs[i].second << "\n";
}