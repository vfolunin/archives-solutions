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

    int size, pairCount;
    string s;
    cin >> size >> pairCount >> s;

    vector<int> seen(26);
    vector<vector<long long>> pairs(26, vector<long long>(26));

    for (char c : s) {
        int cur = c - 'a';
        for (int prev = 0; prev < 26; prev++)
            pairs[prev][cur] += seen[prev];
        seen[cur]++;
    }

    long long res = 0;
    for (int i = 0; i < pairCount; i++) {
        char a, b;
        cin >> a >> b;

        res += pairs[a - 'a'][b - 'a'];
    }

    cout << res;
}