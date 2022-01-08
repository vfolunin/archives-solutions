#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int pairCount;
    cin >> pairCount;

    if (!pairCount)
        return 0;

    vector<int> presents(pairCount * 2);
    for (int &present : presents)
        cin >> present;

    sort(presents.begin(), presents.end());

    vector<int> pairs(pairCount);
    for (int i = 0; i < pairCount; i++)
        pairs[i] = presents[i] + presents[presents.size() - 1 - i];

    sort(pairs.begin(), pairs.end());

    cout << pairs.back() << " " << pairs.front() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}