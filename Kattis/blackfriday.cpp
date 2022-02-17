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

    int rollCount;
    cin >> rollCount;

    vector<vector<int>> rolls(7);
    for (int i = 0; i < rollCount; i++) {
        int roll;
        cin >> roll;
        rolls[roll].push_back(i);
    }

    for (int i = 6; i; i--) {
        if (rolls[i].size() == 1) {
            cout << rolls[i][0] + 1;
            return 0;
        }
    }

    cout << "none";
}