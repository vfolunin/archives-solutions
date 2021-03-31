#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    map<int, set<int>> authorsOf;
    for (int author = 0; author < 3; author++) {
        int problemCount;
        cin >> problemCount;
        for (int i = 0; i < problemCount; i++) {
            int problem;
            cin >> problem;
            authorsOf[problem].insert(author);
        }
    }

    vector<vector<int>> uniqueProblems(3);
    for (auto &[problem, authors] : authorsOf)
        if (authors.size() == 1)
            uniqueProblems[*authors.begin()].push_back(problem);

    int maxUniqueProblemCount = 0;
    for (int author = 0; author < 3; author++)
        maxUniqueProblemCount = max<int>(maxUniqueProblemCount, uniqueProblems[author].size());

    cout << "Case #" << test << ":\n";
    for (int author = 0; author < 3; author++) {
        if (uniqueProblems[author].size() == maxUniqueProblemCount) {
            cout << author + 1 << " " << maxUniqueProblemCount;
            for (int problem : uniqueProblems[author])
                cout << " " << problem;
            cout << "\n";
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}