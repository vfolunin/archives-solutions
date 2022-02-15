#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int studentCount;
    cin >> studentCount;

    vector<int> score(studentCount);
    double averageScore = 0;
    for (int &x : score) {
        cin >> x;
        averageScore += x;
    }
    averageScore /= studentCount;

    double percentage = 0;
    for (int x : score)
        percentage += x > averageScore;
    percentage *= 100.0 / studentCount;

    cout.precision(3);
    cout << fixed << percentage << "%\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}