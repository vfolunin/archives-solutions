#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getWeights() {
    vector<int> counts = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 };
    vector<int> weights;
    for (int i = 0; i < counts.size(); i++)
        for (int j = 0; j < counts[i]; j++)
            weights.push_back(i + 2);
    return weights;
}

void solve() {
    string line;
    getline(cin, line);

    map<char, int> countMap;
    for (char c : line)
        if (c != ' ')
            countMap[c]++;

    vector<int> counts;
    for (auto &[_, count] : countMap)
        counts.push_back(count);
    sort(counts.rbegin(), counts.rend());

    static vector<int> weights = getWeights();

    int res = 0;
    for (int i = 0; i < counts.size(); i++)
        res += counts[i] * weights[i];

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}