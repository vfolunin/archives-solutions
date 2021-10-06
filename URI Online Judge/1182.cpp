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

    int col;
    char op;
    cin >> col >> op;

    vector<vector<double>> a(12, vector<double>(12));
    for (vector<double> &row : a)
        for (double &x : row)
            cin >> x;

    double res = 0;
    for (vector<double> &row : a)
        res += row[col];

    if (op == 'M')
        res /= 12;

    cout.precision(1);
    cout << fixed << res << "\n";
}