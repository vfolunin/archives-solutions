#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int teamCount;
    cin >> teamCount;

    vector<int> teams(teamCount);
    iota(teams.begin(), teams.end(), 1);

    for (int i = 0, j = 0; i < teamCount - 1; i++, j += 2) {
        int winner;
        cin >> winner;
        
        teams.push_back(teams[j + winner - 1]);
    }

    cout << teams.back();
}