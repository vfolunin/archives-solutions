#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int markCount;
    cin >> markCount;

    vector<int> marks(markCount);
    for (int &mark : marks)
        cin >> mark;

    int maxMark = *max_element(marks.begin(), marks.end());

    int curRow = 0, maxRow = 1;
    for (int mark : marks) {
        if (mark == maxMark)
            curRow++;
        else
            curRow = 0;
        maxRow = max(maxRow, curRow);
    }

    cout << "Caso #" << test << ": " << maxRow << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}