#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

int cost(vector<int> &wordMasks, int limit) {
    int res = 0;
    for (int i = 1; res < limit && i < wordMasks.size(); i++)
        res += ones(wordMasks[i - 1] & wordMasks[i]);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wordCount;
    cin >> wordCount;

    vector<int> wordMasks(wordCount);
    for (int &mask : wordMasks) {
        string word;
        cin >> word;
        for (char c : word)
            mask |= 1 << (c - 'A');
    }

    sort(wordMasks.begin(), wordMasks.end());
    int minCost = 1e9;
    do {
        minCost = min(minCost, cost(wordMasks, minCost));
    } while (next_permutation(wordMasks.begin(), wordMasks.end()));

    cout << minCost;
}