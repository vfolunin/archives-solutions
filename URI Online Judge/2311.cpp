#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string name;
    double difficulty;
    cin >> name >> difficulty;

    vector<double> score(7);
    for (double &x : score)
        cin >> x;

    sort(score.begin(), score.end());

    double sum = 0;
    for (int i = 1; i + 1 < score.size(); i++)
        sum += score[i];

    cout.precision(2);
    cout << name << " " << fixed << sum * difficulty << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}