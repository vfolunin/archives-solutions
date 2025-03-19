#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    int targetSum;
    cin >> s >> targetSum;

    unordered_map<char, int> count;
    for (char c : string("ADOPQR"))
        count[c] = 1;
    count['B'] = 2;

    int sum = 0, res = s.size() + 1;
    for (int l = 0, r = 0; r < s.size(); l++) {
        while (r < s.size() && sum < targetSum) {
            sum += count[s[r]];
            r++;
        }
        if (sum == targetSum)
            res = min(res, r - l);
        sum -= count[s[l]];
    }

    cout << (res <= s.size() ? res : -1);
}