#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int curProblems;
    cin >> curProblems;

    if (curProblems < 0)
        return 0;

    vector<int> problemsMade(12);
    for (int &x : problemsMade)
        cin >> x;

    vector<int> problemsNeed(12);
    for (int &x : problemsNeed)
        cin >> x;

    cout << "Case " << test << ":\n";
    for (int i = 0; i < 12; i++) {
        if (curProblems >= problemsNeed[i]) {
            cout << "No problem! :D\n";
            curProblems -= problemsNeed[i];
        } else {
            cout << "No problem. :(\n";
        }
        curProblems += problemsMade[i];
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}