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

    int problemCount, skill;
    cin >> problemCount >> skill;

    vector<pair<int, int>> problems(problemCount);
    for (auto &[a, b] : problems)
        cin >> a >> b;
    sort(problems.begin(), problems.end());

    int res = 0;
    for (auto &[a, b] : problems) {
        if (skill < a)
            break;
        skill += b;
        res++;
    }

    cout << res;
}