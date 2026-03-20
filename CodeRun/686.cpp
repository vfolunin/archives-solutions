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
    cin >> s;

    vector<vector<int>> cost(s.size() + 1, vector<int>(2));
    cost[0] = { 0, 1 };

    for (int i = 0; i < s.size(); i++) {
        cost[i + 1][0] = min(cost[i][0] + (s[i] != 'R'), cost[i][1] + (s[i] != 'L') + 1);
        cost[i + 1][1] = min(cost[i][1] + (s[i] != 'L'), cost[i][0] + (s[i] != 'R') + 1);
    }

    cout << cost[s.size()][1];
}