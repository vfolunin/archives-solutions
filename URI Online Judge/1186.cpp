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

    char op;
    cin >> op;

    vector<vector<double>> a(12, vector<double>(12));
    for (vector<double> &row : a)
        for (double &x : row)
            cin >> x;

    double num = 0, den = 0;
    for (int row = 0; row < a.size(); row++) {
        for (int col = a.size() - row; col < a.size(); col++) {
            num += a[row][col];
            den++;
        }
    }

    if (op == 'M')
        num /= den;

    cout.precision(1);
    cout << fixed << num << "\n";
}