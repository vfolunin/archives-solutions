#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    double curGrade, targetGrade;
    int curClasses, nextClasses;
    cin >> curGrade >> targetGrade >> curClasses >> nextClasses;
    double nextGrade = (targetGrade * (curClasses + nextClasses) - curGrade * curClasses) / nextClasses;

    cout << "Case #" << test << ": ";
    if (0 <= nextGrade && nextGrade <= 10) {
        cout.precision(2);
        cout << fixed << nextGrade << "\n";
    } else {
        cout << "Impossible\n";
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