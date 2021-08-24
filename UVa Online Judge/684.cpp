#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double getDeterminant(vector<vector<double>> &a) {
    int size = a.size();
    double det = 1;

    for (int row = 0, col = 0; row < size && col < size; row++, col++) {
        int bestRow = row;
        for (int i = row + 1; i < size; i++)
            if (abs(a[i][col]) > abs(a[bestRow][col]))
                bestRow = i;

        if (abs(a[bestRow][col]) < 1e-9)
            return 0;

        swap(a[row], a[bestRow]);
        if (row != bestRow)
            det *= -1;
        det *= a[row][row];

        for (int i = 0; i < size; i++) {
            if (i == row)
                continue;
            double k = -a[i][col] / a[row][col];
            for (int j = col; j < size; j++)
                a[i][j] += k * a[row][j];
        }
    }

    return det;
}

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<vector<double>> a(size, vector<double>(size));
    for (vector<double> &row : a)
        for (double &x : row)
            cin >> x;

    cout.precision(0);
    cout << fixed << getDeterminant(a) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
    cout << "*\n";
}