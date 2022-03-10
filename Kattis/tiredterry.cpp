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

    int patternSize, windowSize, minSleep;
    string pattern;
    cin >> patternSize >> windowSize >> minSleep >> pattern;
    pattern += pattern;

    vector<int> p(pattern.size());
    for (int i = 0; i < p.size(); i++) {
        p[i] = pattern[i] == 'Z';
        if (i)
            p[i] += p[i - 1];
    }

    int res = 0;
    for (int l = 0, r = windowSize - 1; l < patternSize; l++, r++)
        res += p[r] - (l ? p[l - 1] : 0) < minSleep;

    cout << res;
}