#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int studentCount;
    cin >> studentCount;

    if (!studentCount)
        return 0;

    vector<int> studentCents(studentCount);
    int averageCents = 0;

    for (int i = 0; i < studentCount; i++) {
        int dollars;
        cin >> dollars;
        cin.ignore();
        cin >> studentCents[i];
        studentCents[i] += dollars * 100;
        averageCents += studentCents[i];
    }

    int residualCents = averageCents % studentCount;
    averageCents /= studentCount;
    sort(studentCents.rbegin(), studentCents.rend());

    int res = 0;
    for (int cents : studentCents) {
        int needCents = averageCents + (bool)residualCents;
        if (cents > needCents)
            res += cents - needCents;
        if (residualCents)
            residualCents--;
    }

    cout << "$" << res / 100 << "." << setw(2) << setfill('0') << res % 100 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}