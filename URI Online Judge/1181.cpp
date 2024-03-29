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

    int row;
    char op;
    cin >> row >> op;

    vector<vector<double>> a(12, vector<double>(12));
    for (vector<double> &row : a)
        for (double &x : row)
            cin >> x;

    double res = 0;
    for (double x : a[row])
        res += x;

    if (op == 'M')
        res /= 12;

    cout.precision(1);
    cout << fixed << res << "\n";
}