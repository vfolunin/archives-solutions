#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    vector<double> mark(7);
    for (double &m : mark)
        cin >> m;

    sort(mark.begin() + 4, mark.end());
    mark[4] = (mark[5] + mark[6]) / 2;

    vector<double> total = { 20, 20, 30, 10, 20 };
    vector<double> weight = { 2, 2, 3, 1, 2 };

    double result = 0;
    for (int i = 0; i < 5; i++)
        result += mark[i] / total[i] * weight[i];

    cout << "Case " << test << ": ";
    for (int i = 0; i < 4; i++) {
        if (result >= 9 - i - 1e-9) {
            cout << (char)('A' + i) << "\n";
            return;
        }
    }
    cout << "F\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}