#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string s;
    cin >> s;

    if (s == "bye")
        return 0;

    vector<vector<int>> ways(s.size() + 1, vector<int>(s.size() * 9 + 1));
    ways[0][0] = 1;

    for (int size = 1; size <= s.size(); size++) {
        int lastSum = 0;
        for (int lastSize = 1; lastSize <= size; lastSize++) {
            lastSum += s[size - lastSize] - '0';
            for (int prevSum = 0; prevSum <= lastSum; prevSum++)
                ways[size][lastSum] += ways[size - lastSize][prevSum];
        }
    }

    int res = 0;
    for (int lastSum = 0; lastSum < ways.back().size(); lastSum++)
        res += ways.back()[lastSum];

    cout << test << ". " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}