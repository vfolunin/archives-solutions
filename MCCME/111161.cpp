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

    int size;
    cin >> size;

    vector<pair<int, string>> pairs(size);
    for (auto &[score, surname] : pairs)
        cin >> surname >> score;

    sort(pairs.rbegin(), pairs.rend());

    for (auto &[score, surname] : pairs)
        cout << surname << "\n";
}