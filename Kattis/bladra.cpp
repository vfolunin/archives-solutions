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

    int problemCount, acCount;
    cin >> problemCount >> acCount;

    vector<int> teamCount(problemCount);
    for (int i = 0; i < acCount; i++) {
        int problem;
        cin >> problem >> problem;

        teamCount[problem - 1]++;
    }

    cout << *min_element(teamCount.begin(), teamCount.end());
}