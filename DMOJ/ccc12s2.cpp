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

    string letters = "IVXLCDM";
    vector<int> values = { 1, 5, 10, 50, 100, 500, 1000 };

    int count;
    char letter;
    vector<pair<int, int>> pairs;
    while (cin >> count >> letter)
        pairs.push_back({ values[letters.find(letter)], count * values[letters.find(letter)] });

    int res = 0;
    for (int i = 0; i < pairs.size(); i++)
        res += (i + 1 < pairs.size() && pairs[i].first < pairs[i + 1].first ? -1 : 1) * pairs[i].second;

    cout << res;
}