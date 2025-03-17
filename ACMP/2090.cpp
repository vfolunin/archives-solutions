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

    string s;
    int targetSum;
    cin >> s >> targetSum;

    int sum = 0, res = 0;
    for (int l = 0, r = 1; r < s.size(); r++) {
        sum += abs(s[r - 1] - s[r]);
        while (sum > targetSum) {
            sum -= abs(s[l] - s[l + 1]);
            l++;
        }
        if (sum == targetSum)
            res = max(res, r - l + 1);
    }

    cout << res;
}