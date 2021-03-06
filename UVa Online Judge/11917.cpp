#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int subjectCount;
    cin >> subjectCount;

    map<string, int> time;
    for (int i = 0; i < subjectCount; i++) {
        string subject;
        cin >> subject >> time[subject];
    }

    int deadline;
    string subject;
    cin >> deadline >> subject;

    cout << "Case " << test << ": ";
    if (time.count(subject) && time[subject] <= deadline + 5)
        cout << (time[subject] <= deadline ? "Yesss\n" : "Late\n");
    else
        cout << "Do your own homework!\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}